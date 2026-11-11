#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
long long c,t,n,d,x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        long long num=x[2]-x[1],sum=0;
        if(num>d)cout<<0<<endl;
        else cout<<n-3<<endl;
    }
    return 0;
}
