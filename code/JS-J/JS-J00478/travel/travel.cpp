#include<bits/stdc++.h>
using namespace std;

struct node{
    int land;
    string seat;
};
node r, x;
int fl1, fl2, fl3, fl4;

void print(){
    cout << fl1 << fl2 << fl3 << fl4;
}

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> r.land >> r.seat >> x.land >> x.seat;
    fl1 = fl2 = fl3 = fl4 = 0;
    if(r.land == x.land){
        fl1 = 1;
        if(r.seat[0] == x.seat[0] && r.seat[1] == x.seat[1]){
            fl2 = 1;
            char rr, xx;
            rr = r.seat[2];
            xx = x.seat[2];
            if('A' <= rr && rr <= 'C' && 'A' <= xx && xx <= 'C'){
                fl3 = 1;
                if(rr + 1 == xx || rr - 1 == xx){
                    fl4 = 1;
                }
            }
            if('D' <= rr && rr <= 'F' && 'D' <= xx && xx <= 'F'){
                fl3 = fl4 = 1;
            }
        }
    }
    print();
    return 0;
}