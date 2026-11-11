#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#define ll long long
#define CSP2026 using
#define plus_plus namespace std
#define debug cout << "check" << endl;

CSP2026 plus_plus;

string c1,c2,s1,s2;
ll n1,n2;
char a1,a2;

bool sid(char a,char b){
    if(a == 'D' && b == 'F') return true;
    if(a == 'F' && b == 'D') return true;
    if(a == 'D' || a == 'F') return false;
    if(b == 'D' || b == 'F') return false;
    return true;
}
bool nei(char a,char b){
    if(a == 'A' && b == 'B') return true;
    if(a == 'B' && b == 'C') return true;
    if(a == 'D' && b == 'E') return true;
    if(b == 'A' && a == 'B') return true;
    if(b == 'B' && a == 'C') return true;
    if(b == 'D' && a == 'E') return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        n1 = s1[0] * 10 + s1[1];
        a1 = s1[2];
        n2 = s2[0] * 10 + s2[1];
        a2 = s2[2];
        //cout << n1 << a1 << endl << n2 << a2;
        if(n1 == n2){
            if(sid(a1,a2)){
                if(nei(a1,a2))
                    cout << "1111";
                else
                    cout << "1110";
            }
            else
                cout << "1100";
        }
        else
            cout << "1000";
    }
    else{
        cout << "0000";
    }

    return 0;
}
