#include <bits/stdc++.h>
using namespace std;
long long n,num[500005],pre[500005];
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    sort(num+1,num+n+1);
    for(int i=2;i<=n;i++){
        pre[i]+=num[i]-num[i-1];
        pre[i+1]+=pre[i];
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        int ans=0,cnt=i;
        long long sum=0,lt=pre[i];
        while(cnt<n){
            cnt++;
            if(sum<=m&&pre[cnt]>pre[i]){
                sum+=(pre[cnt]-pre[i])*(cnt-i);
                pre[i]=pre[cnt];
            }
            if(sum<=m) ans++;
            pre[cnt]-=lt;
        }
        maxn=max(ans,maxn);
    }
    maxn+=1;
    cout<<maxn;
    return 0;
}
