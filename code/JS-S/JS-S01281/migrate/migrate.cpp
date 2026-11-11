#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,x[2000006],sum;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    cin>>n>>d;
    for(int i=1;i<=t;i++){
        sum=0;
        for(int j=1;j<=n;j++){
            cin>>x[j];
            sum+=x[j];
        }
        if(sum<=0) cout<<0;
        else cout<<(sum)/5<<endl;
    }
    return 0;
}
