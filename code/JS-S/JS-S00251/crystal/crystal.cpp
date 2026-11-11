#include <bits/stdc++.h>
using namespace std;
long long n,m,avg,cnt,ans=1,pos=2;
struct x{
    long long bh;
    long long data;
};
bool cmp(struct x a,struct x b){
    return a.data<b.data;
}
bool cmp2(long long a,long long b){
    return abs(a-avg)<abs(b-avg);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    vector<long long> a(n+1);
    vector<x> dist(n+1);
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        dist[i].bh=i;
        for(long long j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            dist[i].data+=abs(a[i]-a[j]);
        }
    }
    sort(dist.begin()+1,dist.end(),cmp);
    avg=a[dist[1].bh];
    sort(a.begin()+1,a.end(),cmp2);
    while(cnt<=m){
        if(pos>n){
            cout<<ans;
            return 0;
        }
        if(cnt+abs(avg-a[pos])<=m){
            cnt+=abs(avg-a[pos]);
            ans++;
            pos++;
        }else{
            cout<<ans;
            return 0;
        }
        if(cnt==m){
            cout<<ans;
            return 0;
        }
    }
    return 0;
}