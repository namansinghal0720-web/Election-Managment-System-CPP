#include <iostream>

#include "../include/ElectionManager.hpp"

using namespace std;

int main()
{
    ElectionManager manager;

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "   Election Management System\n";
        cout << "=====================================\n";

        cout << "1. Register Candidate\n";
        cout << "2. Register Voter\n";
        cout << "3. Create Election\n";
        cout << "4. Add Candidate To Election\n";
        cout << "5. Cast Vote\n";
        cout << "6. Display Candidates\n";
        cout << "7. Display Voters\n";
        cout << "8. Display Elections\n";
        cout << "9. Declare Result\n";
        cout << "10. Exit\n";

        cout << "\nEnter choice : ";
        cin >> choice;

        try
        {

            switch(choice)
            {

            case 1:
            {
                int id;
                int age;
                int electionId;

                string name;
                string department;

                cout << "\nCandidate ID : ";
                cin >> id;

                cout << "Name : ";
                cin >> name;

                cout << "Age : ";
                cin >> age;

                cout << "Department : ";
                cin >> department;

                cout << "Election ID : ";
                cin >> electionId;

                Candidate c(
                    id,
                    name,
                    age,
                    department,
                    electionId
                );

                manager.registerCandidate(c);

                cout << "Candidate Registered Successfully.\n";

                break;
            }

            case 2:
            {
                int id;
                int age;

                string name;
                string department;

                cout << "\nVoter ID : ";
                cin >> id;

                cout << "Name : ";
                cin >> name;

                cout << "Age : ";
                cin >> age;

                cout << "Department : ";
                cin >> department;

                Voter v(
                    id,
                    name,
                    age,
                    department
                );

                manager.registerVoter(v);

                cout << "Voter Registered Successfully.\n";

                break;
            }

            case 3:
            {
                int id;

                string name;

                cout << "\nElection ID : ";
                cin >> id;

                cin.ignore();

                cout << "Election Name : ";

                getline(cin,name);

                Election e(id,name);

                manager.createElection(e);

                cout << "Election Created Successfully.\n";

                break;
            }

            case 4:
            {
                int electionId;

                int candidateId;

                cout << "\nElection ID : ";
                cin >> electionId;

                cout << "Candidate ID : ";
                cin >> candidateId;

                manager.addCandidateToElection(
                    electionId,
                    candidateId
                );

                cout << "Candidate Added.\n";

                break;
            }

            case 5:
            {
                int voterId;

                int candidateId;

                int electionId;

                cout << "\nVoter ID : ";
                cin >> voterId;

                cout << "Candidate ID : ";
                cin >> candidateId;

                cout << "Election ID : ";
                cin >> electionId;

                manager.castVote(
                    voterId,
                    candidateId,
                    electionId
                );

                break;
            }

            case 6:
            {
                manager.displayCandidates();

                break;
            }

            case 7:
            {
                manager.displayVoters();

                break;
            }

            case 8:
            {
                manager.displayElections();

                break;
            }

            case 9:
            {
                int electionId;

                cout << "\nElection ID : ";

                cin >> electionId;

                manager.declareResult(electionId);

                break;
            }

            case 10:
            {
                cout << "\nThank You.\n";

                break;
            }

            default:

                cout << "\nInvalid Choice\n";

            }

        }

        catch(const exception& e)
        {
            cout << "\nError : "
                 << e.what()
                 << endl;
        }

    }
    while(choice != 10);

    return 0;
}