#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pi pair<int,int>
const int N=1e5+5;
int n,m;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if(b[2]=='D'||b[2]=='F'){
        if(d[2]=='D'||d[2]=='F'){
            cout<<"11";
            return 0;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    if(b[2]=='A'){
        if(d[2]=='B'){
            cout<<"11";
            return 0;
        }
        else if(d[2]=='C'){
            cout<<"10";
            return 0;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else if(b[2]=='C'){
        if(d[2]=='B'){
            cout<<"11";
            return 0;
        }
        else if(d[2]=='A'){
            cout<<"10";
            return 0;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else if(b[2]=='B'){
        if(d[2]=='A'||d[2]=='C'){
            cout<<"11";
            return 0;
        }
        else cout<<"00";
    }
    return 0;
}
