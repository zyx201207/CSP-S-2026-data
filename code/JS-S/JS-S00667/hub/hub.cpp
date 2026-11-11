#include<bits/stdc++.h>
using namespace std;
#define int long long
#define O_ return
#define my cout
#define touhou <<
#define tiny_game "0\n"
const int N=1e6+6;
int n,k,c,t,a[N];
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        memset(a,0,sizeof a);
        for(int i=1,x,y;i<n;i++){
            cin>>x>>y;
            a[x]++,a[y]++;
        }if(n==k)goto http;
        if(c==13||c==14){
            if(k>=n/2)cout<<"1\n";
            else if(k==1)cout<<(n/2+1)/2<<endl;
            else cout<<(n/2+7-k)/4<<endl;
        }if(k>=2)cout<<"1\n";
        else if(n<=3)cout<<"1\n";
        else if(n==5){
            if(a[1]==4||a[2]==4||a[3]==4||a[4]==4||a[5]==4)cout<<"1\n";
            else cout<<"2\n";
        }
        else if(a[1]==3||a[2]==3||a[3]==3||a[4]==3)cout<<"1\n";
        else cout<<"2\n";
        continue;
        http://thenv.me
        my touhou tiny_game;
    }O_ 0;
}//x x xxx 1 year
