#include <bits/stdc++.h>
using namespace std;
string sx,sr,x,r;
int cnt;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>x>>sx>>r>>sr;
    if(x==r) cout<<1,cnt++;
    else cout<<0;
    if(sx[0]==sr[0]&&sx[1]==sr[1]&&cnt==1) cout<<1,cnt++;
    else cout<<0;
    if(sx[2]=='A'){
        if(sr[2]=='B'||sr[2]=='C'&&cnt==2) cout<<1,cnt++;
        else cout<<0;
    }
    else if(sx[2]=='B'){
        if(sr[2]=='A'||sr[2]=='C'&&cnt==2) cout<<1,cnt++;
        else cout<<0;
    }
    else if(sx[2]=='C'){
        if(sr[2]=='A'||sr[2]=='B'&&cnt==2) cout<<1,cnt++;
        else cout<<0;
    }
    else if(sx[2]=='D'){
        if(sr[2]=='F'&&cnt==2) cout<<1,cnt++;
        else cout<<0;
    }
    else {
        if(sr[2]=='D'&&cnt==2) cout<<1,cnt++;
        else cout<<0;
    }
    if((sr[2]=='D'&&sx[2]=='C')||(sr[2]=='C'&&sx[2]=='D')) cout<<0;
    else if(abs(sr[2]-sx[2])==1&&cnt==3) cout<<1;
    else cout<<0;
    return 0;
}
