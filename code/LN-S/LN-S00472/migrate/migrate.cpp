#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>>e[500505];
bool vis[500505];
long long d[500505];
long long a[500505];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--){
        memset(a,0,sizeof(a));
        long long n,m;
        cin>>n>>m;
        memset(a,0,sizeof(a));
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }
        if(a[2]-a[1]>m)cout<<0<<endl;
        else {
            long long sum=0;
            for(long long i=2;i<n;i++){
                sum+=min(i-1,n-i);
            }
            cout<<sum<<'\n';
        }
    }
    return 0;
}
