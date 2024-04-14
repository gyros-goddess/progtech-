#include <climits>  
#include <cmath>  
#include <iostream>  
  
#ifndef CONTEST  
#include "specker1.cpp"  
#endif  
  
using namespace std;  
  
class Player {  
protected:  
    string name;  
  
public:  
    Player(const string &n) { name = n; }  
    virtual ~Player() {}  
  
    virtual const string &getType() const = 0;  
    virtual Move play(const State &s) = 0;  
  
    friend ostream &operator<<(ostream &out, const Player &player) {  
        out << player.getType() << " player " << player.name;  
        return out;  
    }  
};  
  
class GreedyPlayer : public Player {  
private:  
    const string type = "Greedy";  
  
public:  
    GreedyPlayer(const string &n) : Player(n) {}  
    virtual ~GreedyPlayer() {}  
  
    const string &getType() const override { return type; }  
  
    Move play(const State &s) override {  
        int maxHeap = 0, maxCoins = 0;  
        for (int i = 0; i < s.getHeaps(); i++) {  
            int coins = s.getCoins(i);  
            if (coins > maxCoins) {  
                maxCoins = coins;  
                maxHeap = i;  
            }  
        }  
  
        Move move(maxHeap, maxCoins, 0, 0);  
        return move;  
    }  
};  
  
class SpartanPlayer : public Player {  
private:  
    const string type = "Spartan";  
  
public:  
    SpartanPlayer(const string &n) : Player(n) {}  
    virtual ~SpartanPlayer() {}  
  
    const string &getType() const override { return type; }  
  
    Move play(const State &s) override {  
        int maxHeap = 0, maxCoins = 0;  
        for (int i = 0; i < s.getHeaps(); i++) {  
            int coins = s.getCoins(i);  
            if (coins > maxCoins) {  
                maxCoins = coins;  
                maxHeap = i;  
            }  
        }  
  
        Move move(maxHeap, 1, 0, 0);  
        return move;  
    }  
};  
  
class SneakyPlayer : public Player {  
private:  
    const string type = "Sneaky";  
  
public:  
    SneakyPlayer(const string &n) : Player(n) {}  
    virtual ~SneakyPlayer() {}  
  
    const string &getType() const override { return type; }  
  
    Move play(const State &s) override {  
        int minHeap = 0, minCoins = INT_MAX;  
        for (int i = 0; i < s.getHeaps(); i++) {  
            int coins = s.getCoins(i);  
            if (coins < minCoins && coins > 0) {  
                minCoins = coins;  
                minHeap = i;  
            }  
        }  
  
        Move move(minHeap, minCoins, 0, 0);  
        return move;  
    }  
};  
  
class RighteousPlayer : public Player {  
private:  
    const string type = "Righteous";  
  
public:  
    RighteousPlayer(const string &n) : Player(n) {}  
    virtual ~RighteousPlayer() {}  
  
    const string &getType() const override { return type; }  
  
    Move play(const State &s) override {  
        int maxHeap = 0, maxCoins = 0;  
        for (int i = 0; i < s.getHeaps(); i++) {  
            int coins = s.getCoins(i);  
            if (coins > maxCoins) {  
                maxCoins = coins;  
                maxHeap = i;  
            }  
        }  
  
        int minHeap = 0, minCoins = INT_MAX;  
        for (int i = 0; i < s.getHeaps(); i++) {  
            int coins = s.getCoins(i);  
            if (coins < minCoins) {  
                minCoins = coins;  
                minHeap = i;  
            }  
        }  
  
        int op = round(maxCoins / 2.0);  
  
        Move move(maxHeap, op, minHeap, op - 1);  
        return move;  
    }  
}; 
