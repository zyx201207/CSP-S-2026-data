#include<bits/stdc++.h>
using namespace std;
unsigned long long d;
long long x[2000005],cha[500005],n,c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        long long del=x[2]-x[1];
        if(d<del) cout<<0<<endl;
        else{
            long long m=d/del;
            cout<<n-m*2+2;
        }
    }
    return 0;
}
