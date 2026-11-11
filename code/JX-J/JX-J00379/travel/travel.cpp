#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;

bool is_line(char a,char b){
     if(a=='A' && b=='B')return true;
     if(a=='B' && b=='C')return true;
     if(a=='A' && b=='C')return true;
     if(a=='D' && b=='F')return true;
     if(a=='F' && b=='D')return true;
     if(a=='B' && b=='A')return true;
     if(a=='B' && b=='C')return true;
     if(a=='C' && b=='A')return true;
   return false;
}

bool xl(char a,char b){
     if(a=='A' && b=='B')return true;
     if(a=='B' && b=='A')return true;
     if(a=='B' && b=='C')return true;
     if(a=='C' && b=='B')return true;
     if(a=='D' && b=='F')return true;
     if(a=='F' && b=='D')return true;
   return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("travel3.in","r",stdin);
    freopen("travel3.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){v.push_back(1);
    }else v.push_back(0);
    if(s1[0] == s2[0] && s1[1]==s2[1]){
        v.push_back(1);
    }else v.push_back(0);
    if(s1[0] == s2[0] && s1[1]==s2[1] && is_line(s1[2],s2[2])){
        v.push_back(1);
    }else v.push_back(0);
    if(s1[0] == s2[0] && s1[1]==s2[1] && is_line(s1[2],s2[2]) && xl(s1[2],s2[2])){
        v.push_back(1);
    }else v.push_back(0);
    for(int d:v)cout << d;
    return 0;
}
