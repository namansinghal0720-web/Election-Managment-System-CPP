#include "../include/Election.hpp"

#include <iostream>

using namespace std;

Election::Election()
{
    electionId = 0;
    winnerId = -1;
}

Election::Election(
    int electionId,
    const string& electionName
)
    :
    electionId(electionId),
    electionName(electionName),
    winnerId(-1)
{
}

int Election::getElectionId() const
{
    return electionId;
}

const string& Election::getElectionName() const
{
    return electionName;
}

int Election::getWinner() const
{
    return winnerId;
}

void Election::setWinner(int winnerId)
{
    this->winnerId = winnerId;
}

void Election::addCandidate(int candidateId)
{
    candidateIds.push_back(candidateId);
}

const vector<int>& Election::getCandidateIds() const
{
    return candidateIds;
}

void Election::display() const
{
    cout << "Election ID   : " << electionId << endl;
    cout << "Election Name : " << electionName << endl;

    cout << "Candidates : ";

    for(int id : candidateIds)
        cout << id << " ";

    cout << endl;
}