#include "../include/ElectionManager.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void ElectionManager::registerCandidate(const Candidate& candidate)
{
    if(candidate.getAge() < MINIMUM_CANDIDATE_AGE)
        throw InvalidAgeException();

    if(candidates.count(candidate.getId()))
        throw DuplicateCandidateException();

    candidates.insert({candidate.getId(), candidate});

    cout << "Candidate Registered Successfully.\n";
}

void ElectionManager::registerVoter(const Voter& voter)
{
    if(voters.count(voter.getId()))
        throw DuplicateVoterException();

    voters.insert({voter.getId(), voter});

    cout << "Voter Registered Successfully.\n";
}

void ElectionManager::createElection(const Election& election)
{
    if(elections.count(election.getElectionId()))
        throw DuplicateElectionException();

    elections.insert({election.getElectionId(), election});

    cout << "Election Created Successfully.\n";
}

void ElectionManager::addCandidateToElection(
        int electionId,
        int candidateId)
{
    auto election = elections.find(electionId);

    if(election == elections.end())
        throw ElectionNotFoundException();

    auto candidate = candidates.find(candidateId);

    if(candidate == candidates.end())
        throw CandidateNotFoundException();

    if(candidate->second.getElectionId() != electionId)
        throw runtime_error(
            "Candidate belongs to another election."
        );

    for(int id : election->second.getCandidateIds())
    {
        if(id == candidateId)
            throw runtime_error(
                "Candidate already added."
            );
    }

    election->second.addCandidate(candidateId);

    cout << "Candidate Added Successfully.\n";
}
void ElectionManager::castVote(
    int voterId,
    int candidateId,
    int electionId)
{
    auto voter = voters.find(voterId);

    if(voter == voters.end())
        throw VoterNotFoundException();

    auto candidate = candidates.find(candidateId);

    if(candidate == candidates.end())
        throw CandidateNotFoundException();

    auto election = elections.find(electionId);

    if(election == elections.end())
        throw ElectionNotFoundException();

    // Candidate should belong to this election
    if(candidate->second.getElectionId() != electionId)
        throw runtime_error(
            "Candidate is not contesting in this election."
        );

    // Candidate must be registered for this election
    bool found = false;

    for(int id : election->second.getCandidateIds())
    {
        if(id == candidateId)
        {
            found = true;
            break;
        }
    }

    if(!found)
        throw runtime_error(
            "Candidate is not registered for this election."
        );

    // Prevent duplicate voting
    if(voter->second.hasVoted(electionId))
        throw AlreadyVotedException();

    voter->second.vote(electionId);

    candidate->second.addVote();

    cout << "\nVote Cast Successfully.\n";
}

void ElectionManager::declareResult(int electionId)
{
    auto election = elections.find(electionId);

    if(election == elections.end())
        throw ElectionNotFoundException();

    vector<Candidate*> electionCandidates;

    for(auto &candidate : candidates)
    {
        if(candidate.second.getElectionId() == electionId)
        {
            electionCandidates.push_back(&candidate.second);
        }
    }

    if(electionCandidates.empty())
    {
        cout << "\nNo candidates registered for this election.\n";
        return;
    }

    int highestVotes = -1;

    for(auto candidate : electionCandidates)
    {
        highestVotes = max(highestVotes,
                           candidate->getVotes());
    }

    if(highestVotes == 0)
    {
        cout << "\nNo votes have been cast.\n";
        return;
    }

    vector<Candidate*> winners;

    for(auto candidate : electionCandidates)
    {
        if(candidate->getVotes() == highestVotes)
        {
            winners.push_back(candidate);
        }
    }

    cout << "\n=========================================\n";
    cout << "RESULT : "
         << election->second.getElectionName()
         << endl;
    cout << "=========================================\n";

    if(winners.size() == 1)
    {
        election->second.setWinner(
            winners[0]->getId());

        cout << "Winner : "
             << winners[0]->getName()
             << endl;

        cout << "Votes  : "
             << winners[0]->getVotes()
             << endl;
    }
    else
    {
        cout << "Election Result : TIE\n";

        cout << "\nCandidates with "
             << highestVotes
             << " votes\n\n";

        for(auto candidate : winners)
        {
            cout << candidate->getName()
                 << " (ID : "
                 << candidate->getId()
                 << ")\n";
        }
    }

    cout << "\n--------------- Ranking ---------------\n";

    sort(
        electionCandidates.begin(),
        electionCandidates.end(),
        [](Candidate* a, Candidate* b)
        {
            return a->getVotes() > b->getVotes();
        });

    int rank = 1;

    for(auto candidate : electionCandidates)
    {
        cout
            << rank << ". "
            << candidate->getName()
            << " (ID "
            << candidate->getId()
            << ") - "
            << candidate->getVotes()
            << " votes\n";

        rank++;
    }

    cout << "---------------------------------------\n";
}

void ElectionManager::displayCandidates() const
{
    if(candidates.empty())
    {
        cout << "\nNo Candidates Registered.\n";
        return;
    }

    vector<int> ids;

    for(const auto &candidate : candidates)
        ids.push_back(candidate.first);

    sort(ids.begin(), ids.end());

    cout << "\n========== Candidates ==========\n\n";

    for(int id : ids)
    {
        candidates.at(id).display();

        cout << endl;
    }
}

void ElectionManager::displayVoters() const
{
    if(voters.empty())
    {
        cout << "\nNo Voters Registered.\n";
        return;
    }

    vector<int> ids;

    for(const auto &voter : voters)
        ids.push_back(voter.first);

    sort(ids.begin(), ids.end());

    cout << "\n========== Voters ==========\n\n";

    for(int id : ids)
    {
        voters.at(id).display();

        cout << endl;
    }
}

void ElectionManager::displayElections() const
{
    if(elections.empty())
    {
        cout << "\nNo Elections Created.\n";
        return;
    }

    vector<int> ids;

    for(const auto &election : elections)
        ids.push_back(election.first);

    sort(ids.begin(), ids.end());

    cout << "\n========== Elections ==========\n\n";

    for(int id : ids)
    {
        elections.at(id).display();

        cout << endl;
    }
}