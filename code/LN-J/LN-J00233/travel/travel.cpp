#include<bits/stdc++.h>
using namespace std;
string a1,a2;
string b1,b2;
string r1,r2;
char s1,s2;
bool check_side(){
    if(s1=='A' || s1=='B' || s1=='C'){
        if(s2=='A' || s2=='B' || s2=='C'){
            return true;
        }
    }
    if(s1=='D' || s1=='F'){
        if(s2=='D' || s2=='F'){
            return true;
        }
    }
    return false;
}
bool check_beside(){
    if(s1=='A' && s2=='B') return true;
    if(s1=='B' && (s2=='A' || s2=='C')) return true;
    if(s1=='C' && s2=='B') return true;
    if(s1=='D' && s2=='F') return true;
    if(s1=='F' && s2=='D') return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>a1>>a2>>b1>>b2;
    r1=a2[0]+a2[1];
    r2=b2[0]+b2[1];
    s1=a2[2];
    s2=b2[2];

    if(a1==b1) printf("1");
    else printf("0");

    if(a1==b1 && r1==r2) printf("1");
    else printf("0");

    if(a1==b1 && r1==r2 && check_side()) printf("1");
    else printf("0");

    if(a1==b1 && r1==r2 && check_beside()) printf("1");
    else printf("0");
    return 0;
}
