#include "../include/Candidate.hpp"

#include <iostream>

using namespace std;

Candidate::Candidate()
    :
    Person()
{
    electionId = 0;
    votes = 0;
}

Candidate::Candidate(
    int id,
    const string& name,
    int age,
    const string& department,
    int electionId
)
    :
    Person(id,name,age,department)
{
    this->electionId = electionId;
    votes = 0;
}

int Candidate::getElectionId() const
{
    return electionId;
}

int Candidate::getVotes() const
{
    return votes;
}

void Candidate::addVote()
{
    votes++;
}

void Candidate::resetVotes()
{
    votes = 0;
}

void Candidate::display() const
{
    cout << "Candidate ID : " << id << endl;
    cout << "Name         : " << name << endl;
    cout << "Age          : " << age << endl;
    cout << "Department   : " << department << endl;
    cout << "Election ID  : " << electionId << endl;
    cout << "Votes        : " << votes << endl;
}