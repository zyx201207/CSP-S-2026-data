#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ull unsigned long long
#define pb push_back
#define mii map<int,int>
#define pii pair<int,int>
#define si stack<int,int>
#define qi queue<int,int>
#define miao return 0;
using namespace std;

int c1,c2;
string s1,s2;

bool check(char c1,char c2){
    if(((c1 == 'A' || c1 == 'B' || c1 == 'C') && (c2 == 'A' || c2 == 'B' || c2 == 'C')) || ((c1 == 'D' || c1 == 'F') && (c2 == 'D' || c2 == 'F'))){
        return 1;
    }else{
        return 0;
    }
}

bool nt(char c1,char c2){
    if((c1 == 'A' && c2 == 'B') || (c1 == 'B' && (c2 == 'A' || c2 == 'C')) || (c1 == 'C' && c2 == 'B') || (c1 == 'D' && c2 == 'F') || (c1 == 'F' && c2 == 'D')){
        return 1;
    }else{
        return 0;
    }
}

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 == c2) cout << 1;
    else cout << 0;

    int pos = 10 * (s1[0]-'0') + (s1[1]-'0');
    int poss = 10 * (s2[0]-'0') + (s2[1]-'0');
    if(c1 == c2 && pos == poss) cout << 1;
    else cout << 0;

    char c=s1[2],cc=s2[2];
    if(c1 == c2 && pos == poss && check(c,cc)) cout << 1;
    else cout << 0;

    if(c1 == c2 && pos == poss && check(c,cc) && nt(c,cc)) cout << 1;
    else cout << 0;

    miao
}