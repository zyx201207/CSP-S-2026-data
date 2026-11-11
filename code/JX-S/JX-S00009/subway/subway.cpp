#include <bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>> g(550);
long long a[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        long long p,last=0,lastw=0;
        cin>>p;
        long long v,w;
        cin>>v>>w;
        last=v;
        lastw=w;
        for(int j=2;j<=p;j++){
            cin>>v>>w;
            g(last).push_back({v,lastw});
            last=v;
            lastw=w;
            if(j==p){
                g(v).push_back({1<<62,w})
            }
        }
    }
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        long long sum=a[l]+a[r];
        for(int j=1;j<=g(l).size();j++){
            sum+=g(l).w;
        }
    }
    cout<<sum;
    return 0;
}
