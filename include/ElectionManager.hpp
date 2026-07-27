#ifndef ELECTIONMANAGER_HPP
#define ELECTIONMANAGER_HPP

#include <unordered_map>

#include "Candidate.hpp"
#include "Election.hpp"
#include "Exceptions.hpp"
#include "Voter.hpp"

class ElectionManager
{
private:

    std::unordered_map<int, Candidate> candidates;
    std::unordered_map<int, Voter> voters;
    std::unordered_map<int, Election> elections;

    static constexpr int MINIMUM_CANDIDATE_AGE = 18;

public:

    // Registration
    void registerCandidate(const Candidate& candidate);
    void registerVoter(const Voter& voter);
    void createElection(const Election& election);

    // Election Operations
    void addCandidateToElection(int electionId, int candidateId);
    void castVote(int voterId, int candidateId, int electionId);
    void declareResult(int electionId);

    // Display
    void displayCandidates() const;
    void displayVoters() const;
    void displayElections() const;
};

#endif