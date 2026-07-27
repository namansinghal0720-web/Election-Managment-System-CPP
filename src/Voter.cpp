#include "../include/Voter.hpp"

#include <iostream>

using namespace std;

Voter::Voter()
    :
    Person()
{
}

Voter::Voter(
    int id,
    const string& name,
    int age,
    const string& department
)
    :
    Person(id,name,age,department)
{
}

bool Voter::hasVoted(int electionId) const
{
    return votedElections.find(electionId) != votedElections.end();
}

void Voter::vote(int electionId)
{
    votedElections.insert(electionId);
}

void Voter::display() const
{
    cout << "Voter ID    : " << id << endl;
    cout << "Name        : " << name << endl;
    cout << "Age         : " << age << endl;
    cout << "Department  : " << department << endl;
}