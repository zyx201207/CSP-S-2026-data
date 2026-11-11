#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N=200010,d[6]={0,0,0,1,1,1};

void solve(){
    string s1,s2,t1,t2;
    cin>>s1>>s2>>t1>>t2;
    if(s1==t1) cout<<"1";
    else{cout<<"0000";return;}
    if(s2.substr(0,2)==t2.substr(0,2)) cout<<"1";
    else{cout<<"000";return;}
    char x=s2[2]-'A',y=t2[2]-'A';
    if(d[x]==d[y])cout<<"1";
    else{cout<<"00";return;}
    if(x>y) swap(x,y);
    if((y<3&&x==y-1)||(y==5&&x==3)) cout<<"1";
    else cout<<"0";
    cout<<"\n";
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--) solve();
}
