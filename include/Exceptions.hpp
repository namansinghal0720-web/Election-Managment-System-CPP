#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>

class CandidateNotFoundException : public std::runtime_error
{
public:
    CandidateNotFoundException()
        : std::runtime_error("Candidate not found")
    {
    }
};

class VoterNotFoundException : public std::runtime_error
{
public:
    VoterNotFoundException()
        : std::runtime_error("Voter not found")
    {
    }
};

class ElectionNotFoundException : public std::runtime_error
{
public:
    ElectionNotFoundException()
        : std::runtime_error("Election not found")
    {
    }
};

class AlreadyVotedException : public std::runtime_error
{
public:
    AlreadyVotedException()
        : std::runtime_error("Voter has already voted in this election")
    {
    }
};

class DuplicateCandidateException : public std::runtime_error
{
public:
    DuplicateCandidateException()
        : std::runtime_error("Candidate ID already exists")
    {
    }
};

class DuplicateVoterException : public std::runtime_error
{
public:
    DuplicateVoterException()
        : std::runtime_error("Voter ID already exists")
    {
    }
};

class DuplicateElectionException : public std::runtime_error
{
public:
    DuplicateElectionException()
        : std::runtime_error("Election ID already exists")
    {
    }
};

class InvalidAgeException : public std::runtime_error
{
public:
    InvalidAgeException()
        : std::runtime_error("Candidate age does not satisfy the minimum requirement")
    {
    }
};

#endif