#ifndef ELECTION_HPP
#define ELECTION_HPP

#include <string>
#include <vector>

class Election
{
private:

    int electionId;

    std::string electionName;

    std::vector<int> candidateIds;

    int winnerId;

public:

    Election();

    Election(
        int electionId,
        const std::string& electionName
    );

    int getElectionId() const;

    const std::string& getElectionName() const;

    int getWinner() const;

    void setWinner(int winnerId);

    void addCandidate(int candidateId);

    const std::vector<int>& getCandidateIds() const;

    void display() const;
};

#endif