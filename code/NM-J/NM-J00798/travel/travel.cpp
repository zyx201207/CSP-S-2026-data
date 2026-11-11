#include<bits/stdc++.h>
using namespace std;
int Rx, Xx;  //che xiang
string Rs, Xs;  //zuo wei
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> Rx >> Rs >> Xx >> Xs;
    if(Rx == Xx){
        if(Rs[0] == Xs[0] && Rs[1] == Xs[1]){
            if((('A' <= Rs[2] && 'C' >= Rs[2]) && ('A' <= Xs[2] && 'C' >= Xs[2])) || (('D' <= Rs[2] && 'E' >= Rs[2]) && ('D' <= Xs[2] && 'E' >= Xs[2]))){
                if((Rs[2] == 'A' && Xs[2] == 'B') || (Rs[2] == 'B' && (Xs[2] == 'A' || Xs[2] == 'C')) || (Rs[2] == 'C' && Xs[2] == 'B') || (Rs[2] == 'D' && Xs[2] == 'E') || (Rs[2] == 'E' && Xs[2] == 'D')){
                    cout << "1111";
                }
                else cout << "1110";
            }
            else cout << "1100";
        }
        else cout << "1000";
    }
    else cout << "0000";
    return 0;
}
