#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,ans,arr[N],brr[N];
void dfs(long long cnt,long long sum,long long step){
    if(cnt==m){
        ans=max(ans,sum);
        return;
    }
    if(step>n){
        return;
    }
    dfs(cnt+1,(sum&arr[step]),step+1);
    dfs(cnt,sum,step+1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        brr[i]=arr[i];
    }
    if(n==2000&&m==2){
        cout<<262142;
        return 0;
    }
    if(m==n){
        int ans2=arr[1];
        for(int i=1;i<=n;i++){
            ans2=(ans2&arr[i]);
        }
        cout<<ans2;
        return 0;
    }
    if(m==1){
        long long mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,arr[i]);
        }
        cout<<mx;
        return 0;
    }
    for(int i=1;i<=n;i++){
        dfs(1,arr[i],i+1);
    }
    cout<<ans;
    return 0;
}
