#ifndef CANDIDATE_HPP
#define CANDIDATE_HPP

#include "Person.hpp"

class Candidate : public Person
{
private:

    int electionId;

    int votes;

public:

    Candidate();

    Candidate(
        int id,
        const std::string& name,
        int age,
        const std::string& department,
        int electionId
    );

    int getElectionId() const;

    int getVotes() const;

    void addVote();

    void resetVotes();

    void display() const override;
};

#endif