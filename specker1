#include <iostream>  
#include <algorithm>  
#include <stdexcept>  
using namespace std;  
  
class Move {  
public:  
    Move(int sh, int sc, int th, int tc) : sh(sh), sc(sc), th(th), tc(tc){}  
    int getSource() const { return sh; }  
    int getSourceCoins() const { return sc; }  
    int getTarget() const { return th; }  
    int getTargetCoins() const { return tc; }  
  
    friend ostream &operator<<(ostream &out, const Move &move) {  
        out << "takes " << move.sc << " coins from heap " << move.sh  
            << " and puts ";  
  
        if (move.tc > 0) {  
            out << move.tc << " coins to heap " << move.th;  
        } else {  
            out << "nothing";  
        }  
  
        return out;  
    }  
  
protected:  
    int sh, sc, th, tc;  
};  
  
class State {  
public:  
    State(int h, const int c[], int n) {  
        len = h;  
        p = n;  
        heaps = new int[h];  
        for (int i = 0; i < len; i++)  
            heaps[i] = c[i];  
        currentplayer = 0;  
    }  
  
    ~State() { delete[] heaps; }  
  
    void next(const Move &move) throw(logic_error) {  
        int sh = move.getSource(), th = move.getTarget(),  
                sc = move.getSourceCoins(), tc = move.getTargetCoins();  
  
        if ((sh < 0 || sh >= len) || (th < 0 || th >= len))  
            throw logic_error("invalid heap");  
  
        if (sc > heaps[sh] || tc >= sc)  
            throw logic_error("not enough coins");  
  
        heaps[sh] -= sc;  
        if (tc > 0)  
            heaps[th] += tc;  
  
        currentplayer= (currentplayer+ 1) % p;  
    }  
  
    bool winning() const {  
        bool result = true;  
        for (int i = 0; i < len; i++) {  
            if (heaps[i] != 0) {  
                result = false;  
                break;  
            }  
        }  
        return result;  
    }  
  
    int getHeaps() const { return len; }  
  
    int getCoins(int h) const {  
        if (h < 0 || h >= len)  
            throw logic_error("invalid heap");  
        else  
            return heaps[h];  
    }  
  
    int getPlayers() const { return p; }  
    int getPlaying() const { return currentplayer;}  
  
    friend ostream &operator<<(ostream &out, const State &state) {  
        for (int i = 0; i < state.len - 1; i++) {  
            out << state.heaps[i] << ", ";  
        }  
        out << state.heaps[state.len - 1] << " with " << state.currentplayer <<"/"  
            << state.p << " playing next";  
  
        return out;  
    }  
  
protected:  
    int len, p, *heaps;  
  
private:  
    int currentplayer;  
}; 
