#include <iostream>
#include <string>
using namespace std;

static int no_of_elections, no_of_voters, no_of_candidates;

struct candidate {
    string name;
    int rollno;
    string department;
    int election;
    int age;
};

struct voter {
    string name;
    int rollno;
    string department;
    int age;
    int* vote;
};

void cinitialize(candidate& a) {
    cout << "Enter name of candidate:" << endl;
    cin >> a.name;
    cout << "Enter rollno:" << endl;
    cin >> a.rollno;
    cout << "Enter department:" << endl;
    cin >> a.department;
    cout << "Enter age" << endl;
    cin >> a.age;
    cout << "Enter election for which you are contesting for:" << endl;
    cin >> a.election;
}

void vinitialize(voter& a, int num_elections) {
    int m = 0;
    cout << "Enter voter name:" << endl;
    cin >> a.name;
    cout << "Enter rollno:" << endl;
    cin >> a.rollno;
    cout << "Enter age:" << endl;
    cin >> a.age;
    cout << "Enter department:" << endl;
    cin >> a.department;

    a.vote = new int[num_elections];

    for (int i = 0; i < num_elections; i++) {
        cout << "Don't want to vote to any candidate, type -1 or if satisfied type 0" << endl;
        cin >> m;
        if (m == 0) {
            cout << "Enter vote for election " << i + 1 << endl;
            cin >> a.vote[i];
            cout << "Want to change vote, if yes type -1 or if satisfied type 0" << endl;
            cin >> m;
            if (m == -1) {
                cin >> a.vote[i];
            }
        } else {
            a.vote[i] = -1;
        }
    }
}

void merge(int a[], int low, int mid, int high) {
    int t[high - low + 1];
    int left = low, right = mid + 1, i = 0;
    while (left <= mid && right <= high) {
        if (a[left] < a[right]) {
            t[i++] = a[left++];
        } else if (a[left] > a[right]) {
            t[i++] = a[right++];
        } else {
            t[i++] = a[left++];
            right++;
        }
    }
    while (left <= mid) {
        t[i] = a[left++];
        i++;
    }
    for (int i = low; i <= high; i++) {
        a[i] = t[i - low];
    }
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void result(candidate* c, voter* v, int d) {
    int a[d] = {0};

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < no_of_elections; j++) {
            if ((c + i)->election == j + 1) {
                for (int k = 0; k < no_of_voters; k++) {
                    if ((v + k)->vote[j] == i) {
                        a[i]++;
                        cout << "Vote counted: Voter " << k << " voted for Candidate " << i
                             << " in Election " << j + 1 << endl;
                    }
                }
            }
        }
    }

    int rank[d][2]; // [votes, rank]
    for (int l = 0; l < d; l++) {
        rank[l][0] = a[l];
        rank[l][1] = -1; // Initialize all to -1
    }

    mergeSort(a, 0, d - 1);

    for (int i = 0; i < no_of_elections; i++) {
        int current_rank = 0;
        int top_votes = -1;
        int winner_index = -1;

        for (int k = d - 1; k >= 0; k--) { // Start from highest vote
            for (int p = 0; p < d; p++) {
                if (rank[p][0] == a[k] && (c + p)->election == i + 1 && rank[p][1] == -1) {
                    rank[p][1] = current_rank;
                    if (current_rank == 0) {
                        top_votes = rank[p][0];
                        winner_index = p;
                    }
                    current_rank++;
                }
            }
        }

        if (winner_index != -1) {
            cout << "Election " << i + 1 << " won by " << (c + winner_index)->name
                 << " by securing " << rank[winner_index][0] << " votes" << endl;

            for (int p = 0; p < d; p++) {
                if (rank[p][1] > 0 && (c + p)->election == i + 1) {
                    cout << (c + p)->name << " lost by "
                         << top_votes - rank[p][0]
                         << " votes from " << (c + winner_index)->name
                         << " and is on " << rank[p][1] + 1
                         << "th position in election " << i + 1 << endl;
                }
            }
        } else {
            cout << "No winner in Election " << i + 1 << " (no valid candidates or votes)" << endl;
        }
    }
}
int main() {
    int d = 0;
    cout << "One candidate can contest only for one election only" << endl;
    cout << "Enter minimum age for fighting elections" << endl;
    int age;
    cin >> age;

    cout << "Enter no. of candidates applying for elections:" << endl;
    cin >> no_of_candidates;
    cout << "Enter no. of voters:" << endl;
    cin >> no_of_voters;
    cout << "Enter no. of elections going to take place:" << endl;
    cin >> no_of_elections;

    candidate* c = new candidate[no_of_candidates];
    voter* v = new voter[no_of_voters];

    for (int i = 0; i < no_of_candidates; i++) {
        cinitialize(*(c + i));
        if ((c + i)->age < age) {
            cout << "Candidate rejected due to age limit" << endl;
            i--;
        } else {
            cout << "Candidate accepted" << endl;
            cout << "Candidate registration no.=" << d << endl;
            d++;
        }
    }

    for (int i = 0; i < no_of_voters; i++) {
        vinitialize(*(v + i), no_of_elections);
    }

    result(c, v, d);
    return 0;
}
