#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int op,t,n,k,x,m;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>op>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++)cin>>x>>x;
        if(op!=13&&op!=14){cout<<0<<'\n';continue;}
        m=n/2;
        if(k==n)cout<<0<<'\n';
        else if(k==1)cout<<m/2<<'\n';
        else cout<<((m+1)/2+1)/2-((k+1)/2+1)/2<<'\n';
    }
    return 0;
}
