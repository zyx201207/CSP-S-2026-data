#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,k) for(ll i=j;i<=k;i++)
ll T,n;
ll a[6]={0,0,0,1,0,1};
int main(){
//cout<<1;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
  //  cout<<1;
    //cin>>T;
    T=1;
    while(T--){
        string s1,s2,t1,t2;
        cin>>s1>>s2>>t1>>t2;
        //cout<<t1<<s1<<s2<<t2<<1;

        if(s1==t1) cout<<1;
        else {
            cout<<"0000";
            return 0;
        }
        if(s2[0]==t2[0]&&s2[1]==t2[1]) cout<<1;
        else {
            cout<<"000";
            return 0;
        }

        if(a[s2[2]-'A']==a[t2[2]-'A']) cout<<1;
        else {
            cout<<"00";
            return 0;
        }

        if(abs(s2[2]-t2[2])==2&&(s2[2]=='A'||t2[2]=='A')) cout<<0;
        else cout<<1;
        //cout<<abs(s2[2]-t2[2]);
    }
    return 0;
}

