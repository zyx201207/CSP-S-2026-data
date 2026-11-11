#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(char a,char b){
    if(a=='A' || a=='B' || a=='C'){
        if(b=='A' || b=='B' || b=='C') return 1;
        return 0;
    }
    else{
        if(b=='D' || b=='F') return 1;
        return 0;
    }
}
bool checkl(char a,char b){
    if((a=='D' && b=='F') || (a=='F' && b=='D')) return 1;
    if(abs(int(a)-int(b))==1) return 1;
    return 0;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int c1,c2; //in and check
    int p1,p2;
    char l1,l2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    l1=s1[2],l2=s2[2];
    p1=int(s1[0])*10+s1[1];
    p2=int(s2[0])*10+s2[1];

    if(c1==c2) cout<<1; //first question: same c
    else{cout<<"0000";return 0;}
    if(p1==p2) cout<<1; //second question: same p
    else{cout<<"000";return 0;}
    if(check(l1,l2)) cout<<1;
    else{cout<<"00";return 0;}

    if(p1==p2 && checkl(l1,l2)) cout<<1;
    else cout<<0;
    return 0;
}
