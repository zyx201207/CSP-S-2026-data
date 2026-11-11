#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define yes cout<< "1"
#define no cout<< "0"
using ll = long long;
string s,c,ss,cc;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s>>c>>ss>>cc;
    if(s==ss) yes;
    else {
        no;no;no;no;
        return 0;
    }
    if(c[0]==cc[0]&&c[1]==cc[1]) yes;
    else {
        no;no;no;
        return 0;
    }
    if(c[2]=='A'){
        if(cc[2]=='B'||cc[2]=='C') yes;
        else {
            no;no;
            return 0;
        }
    }
    if(c[2]=='B'){
        if(cc[2]=='A'||cc[2]=='C') yes;
        else {
            no;no;
            return 0;
        }
    }
    if(c[2]=='C'){
        if(cc[2]=='A'||cc[2]=='B') yes;
        else {
            no;no;
            return 0;
        }
    }
    if(c[2]=='D'){
        if(cc[2]=='E') yes;
        else {
            no;no;
            return 0;
        }
    }
    if(c[2]=='E'){
        if(cc[2]=='D') yes;
        else {
            no;no;
            return 0;
        }
    }
    if(c[2]=='A'){
        if(cc[2]=='B') yes;
        else no;
    }
    if(c[2]=='B'){
        if(cc[2]=='A'||cc[2]=='C') yes;
        else no;
    }
    if(c[2]=='C'){
        if(cc[2]=='B') yes;
        else no;
    }
    if(c[2]=='D'){
        if(cc[2]=='E') yes;
        else no;
    }
    if(c[2]=='E'){
        if(cc[2]=='D') yes;
        else no;
    }
    return 0;
}
