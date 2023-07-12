#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <map>

using namespace std;

struct IsEven {
    bool operator()(int number) const {
        return (number % 2) == 0;
    }
};

struct AllEqual {
    bool operator()(string x, string y, string z, string compare_to) {
        if (x == compare_to && y == compare_to && z == compare_to){
            return true;
        } else {
            return false;
        };
    };
};
string getUserInput(string character) {
    cout << "IT IS " << character << "'s TURN!" << endl;
    cout << "Type the address of the cell you want to " << character << ": " << endl;
    string answer;
    cin >> answer;
    return answer;
};

int enviroment(array<string, 9> &addresses) {
    string foundation_frames = "  =============";
    string tile = "|";

    cout << "   " << " A " <<  " " << " B " << " " << " C " << endl
         << foundation_frames << endl
         << "1 " << tile << addresses[0] <<  tile << addresses[1] << tile << addresses[2] << tile << endl
         << foundation_frames << endl
         << "2 " << tile << addresses[3] <<  tile << addresses[4] << tile << addresses[5] << tile << endl
         << foundation_frames << endl
         << "3 " << tile << addresses[6] <<  tile << addresses[7] << tile << addresses[8] << tile << endl
         << foundation_frames << endl;

    return 0;
};

int gameLogic(array<string, 9> &addresses, string character, int* p_num_control) {
    string input = getUserInput(character);

    cout << "Adress: " << input << endl;

    map<string, int> caseMap = {{"a1", 1}, {"a2", 2}, {"a3", 3}, {"b1", 4}, {"b2", 5}, {"b3", 6}, {"c1", 7}, {"c2", 8}, {"c3", 9}};

    switch (caseMap[input])
    {
    case 1:
        if (addresses[0] == "   "){
            addresses[0] = character;
        };
        break;
    case 2:
        if (addresses[3] == "   "){
            addresses[3] = character;
        };
        break;
    case 3:
        if (addresses[6] == "   "){
            addresses[6] = character;
        };
        break;
    case 4:
        if (addresses[1] == "   "){
            addresses[1] = character;
        };
        break;
    case 5:
        if (addresses[4] == "   "){
            addresses[4] = character;
        };
        break;
    case 6:
        if (addresses[7] == "   "){
            addresses[7] = character;
        };
        break;
    case 7:
        if (addresses[2] == "   "){
            addresses[2] = character;
        };
        break;
    case 8:
        if (addresses[5] == "   "){
            addresses[5] = character;
        };
        break;
    case 9:
        if (addresses[8] == "   "){
            addresses[8] = character;
        };
        break;
    
    
    default:
        cout << "// WRONG VALUE //" << endl
             << "-- Example: 'a1' --" << endl;

        ++*p_num_control;
    }

    enviroment(addresses);

    return 0;
};

bool gameOver(array<string, 9> &addresses){
    string character_cross = " X ";
    string character_circle = " O ";

    if (addresses[0] == character_cross){
        cout << "**WINNER IS: " << character_cross << " !!!**";
    } else {
        cout << "**WINNER IS: " << character_circle << " !!!**";
    };

    return true;
}

int main() {
    string character_cross = " X ";
    string character_circle = " O ";

    bool game_Over = false;
    int num_control = 0;

    IsEven isEven;
    AllEqual allequal;

    array<string, 9> addresses;
    fill(begin(addresses), end(addresses), "   ");

    cout << "TIK-TAK-TOE GAME!" << endl;
    enviroment(addresses);

    do {
        if (isEven(num_control) == true) {
            gameLogic(addresses, character_cross, &num_control);
            ++num_control;
        } else {
            gameLogic(addresses, character_circle, &num_control);
            ++num_control;
        };

        if (allequal(addresses[0], addresses[1], addresses[2], character_cross) || allequal(addresses[0], addresses[1], addresses[2], character_circle) ) {
            game_Over = gameOver(addresses);

        } else if (allequal(addresses[6], addresses[7], addresses[8], character_cross) || allequal(addresses[6], addresses[7], addresses[8], character_circle)) {
            game_Over = gameOver(addresses);

        } else if (allequal(addresses[0], addresses[3], addresses[6], character_cross) || allequal(addresses[0], addresses[3], addresses[6], character_circle)) {
            game_Over = gameOver(addresses);

        } else if (allequal(addresses[2], addresses[5], addresses[8], character_cross) || allequal(addresses[2], addresses[5], addresses[8], character_circle)) {
            game_Over = gameOver(addresses);

        } else if (allequal(addresses[0], addresses[4], addresses[8], character_cross) || allequal(addresses[0], addresses[4], addresses[8], character_circle)) {
            game_Over = gameOver(addresses);

        } else if (allequal(addresses[2], addresses[4], addresses[6], character_cross) || allequal(addresses[2], addresses[4], addresses[6], character_circle)) {
            game_Over = gameOver(addresses);

        };
    }while (game_Over == false);

    return 0;
};
