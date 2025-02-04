#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
    // Input symbols
    int numSymbols;
    cout << "Number of input symbols: ";
    cin >> numSymbols;

    set<char> inputSymbols;
    cout << "Input symbols: ";
    for (int i = 0; i < numSymbols; i++) {
        char symbol;
        cin >> symbol;
        inputSymbols.insert(symbol);
    }

    // States
    int numStates;
    cout << "Enter number of states: ";
    cin >> numStates;

    // Start state
    int startState;
    cout << "Initial state: ";
    cin >> startState;

    // Accepting states
    int numAcceptStates;
    cout << "Number of accepting states: ";
    cin >> numAcceptStates;

    set<int> acceptStates;
    cout << "Accepting states: ";
    for (int i = 0; i < numAcceptStates; i++) {
        int state;
        cin >> state;
        acceptStates.insert(state);
    }

    // Transition table
    map<pair<int, char>, int> transitionTable;
    int numTransitions;
    cout << "Enter number of transitions: ";
    cin >> numTransitions;

    cout << "Transition table (e.g., '1 a 2' for 1 to a -> 2): " << endl;
    for (int i = 0; i < numTransitions; i++) {
        int fromState, toState;
        char symbol;
        cin >> fromState >> symbol >> toState;
        transitionTable[{fromState, symbol}] = toState;
    }

    // Input string to validate
    string inputString;
    cout << "Input string: ";
    cin >> inputString;

    // Validate string
    int currentState = startState;
    bool isValid = true;

    for (char symbol : inputString) {
        if (inputSymbols.find(symbol) == inputSymbols.end()) {
            cout << "Invalid String (Invalid symbol)" << endl;
            isValid = false;
            break;
        }
        if (transitionTable.find({currentState, symbol}) == transitionTable.end()) {
            cout << "Invalid String (Undefined transition)" << endl;
            isValid = false;
            break;
        }
        currentState = transitionTable[{currentState, symbol}];
    }

    if (isValid) {
        if (acceptStates.find(currentState) != acceptStates.end()) {
            cout << "Valid String" << endl;
        } else {
            cout << "Invalid String" << endl;
        }
    }

    return 0;
}
