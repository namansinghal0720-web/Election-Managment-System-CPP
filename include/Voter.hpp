#ifndef VOTER_HPP
#define VOTER_HPP

#include "Person.hpp"
#include <unordered_set>

class Voter : public Person
{
private:

    std::unordered_set<int> votedElections;

public:

    Voter();

    Voter(
        int id,
        const std::string& name,
        int age,
        const std::string& department
    );

    bool hasVoted(int electionId) const;

    void vote(int electionId);

    void display() const override;
};

#endif