#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1[1]==c2[1]){
        cout << 1;
        if(s1[1]==s2[1]){
            cout << 1;
            if(65<=s1[2] && s1[2]<=67 && 65<=s2[2] && s2[2]<=67){
                cout << 1;
                if(s1[2]-s2[2]==1 || s1[2]-s2[2]==-1)   cout << 1;
                else   cout << 0;
            }
            else if(68<=s1[2] && s1[2]<=69 && 68<=s2[2] && s2[2]<=69){
                cout << 1;
                if(s1[2]-s2[2]==1 || s1[2]-s2[2]==-1)   cout << 1;
                else   cout << 0;
            }
            else   cout << 0 << 0;
        }
        else   cout << 0 << 0 << 0;
    }
    else   cout << 0 << 0 << 0 << 0;

    return 0;
}
