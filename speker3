#include <iostream>  
  
#ifndef CONTEST  
#include "specker2.cpp"  
#endif  
  
using namespace std;  
  
class Game {  
public:  
    Game(int heaps, int players) {  
        heapsLen = heaps;  
        playersLen = players;  
        heapsArr = new int[heaps];  
        playersArr = new Player *[players];  
        currentHeap = 0, currentPlayer = 0;  
    }  
    ~Game() {}  
  
    void addHeap(int coins) throw(logic_error) {  
        if (currentHeap >= heapsLen)  
            throw logic_error("no more heaps");  
        heapsArr[currentHeap++] = coins;  
    }  
  
    void addPlayer(Player *player) throw(logic_error) {  
        if (currentPlayer >= playersLen)  
            throw logic_error("no more players");  
        playersArr[currentPlayer++] = player;  
    }  
  
    void play(ostream &out) throw(logic_error) {  
        State state = State(heapsLen, heapsArr, playersLen);  
        int p = 0;  
  
        while (!state.winning()) {  
            out << "State: " << state << endl;  
  
            p = state.getPlaying();  
            Move move = playersArr[p]->play(state);  
            state.next(move);  
  
            out << *playersArr[p] << " " << move << endl;  
        }  
  
        out << "State: " << state << endl << *playersArr[p] << " wins" << endl;  
    }  
  
    int getPlayers() const { return playersLen; }  
  
    const Player *getPlayer(int p) const throw(logic_error) {  
        if (p < 0 || p >= playersLen)  
            throw logic_error("no such player");  
        return playersArr[p];  
    }  
  
private:  
    int *heapsArr;  
    Player **playersArr;  
  
    int currentHeap, currentPlayer, heapsLen, playersLen;  
};  
