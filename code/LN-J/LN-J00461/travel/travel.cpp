#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << 1;
    else cout << 0;
    string x,y;
    for(int i = 0;i <= s1.size() - 1;i++){
        if(s1[i] >= '0' && s1[i] <= '9') x += s1[i];
    }
    for(int i = 0;i <= s2.size() - 1;i++){
        if(s2[i] >= '0' && s2[i] <= '9') y += s2[i];
    }
    if(c1 == c2){
        if(x == y) cout << 1;
        else cout << 0;
    }
    else cout << 0;
    int n = s1.size() - 1,m = s2.size() - 1;
    if(c1 == c2){
        if(x == y){
            if((s1[n] == 'A' && s2[m] == 'B') || (s1[n] == 'A' && s2[m] == 'C') || (s1[n] == 'B' && s2[m] == 'C') || (s1[n] == 'D' && s2[m] == 'F')) cout << 1;
            else cout << 0;
        }
        else cout << 0;
    }
    else cout << 0;
    if(c1 == c2){
        if(x == y){
            if((s1[n] == 'A' && s2[m] == 'B') || (s1[n] == 'A' && s2[m] == 'C') || (s1[n] == 'B' && s2[m] == 'C') || (s1[n] == 'D' && s2[m] == 'F')){
                if((s1[n] == 'A' && s2[m] == 'B') || (s1[n] == 'B' && s2[m] == 'C') || (s1[n] == 'D' && s2[m] == 'F')) cout << 1;
                else cout << 0;
            }
            else cout << 0;
        }
        else cout << 0;
    }
    else cout << 0;
}
