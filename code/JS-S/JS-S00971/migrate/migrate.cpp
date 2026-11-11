#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
ll c,t,n,d,x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        int d0=x[2]-x[1];
        int k=d/d0;
        if(k==0 || k==1)cout<<0<<"\n";
        else cout<<max(n-(2*k-1),0*1ll)<<"\n";
    }
    return 0;
}
