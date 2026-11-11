#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
bool flag=true;
int n,m,s,mx,ans,a[maxn];
void dfs(int dep,int sum,int cnt){
    if(cnt==m){
        ans=max(ans,sum);
        return;
    }
    if(n-dep+1+cnt<m)
        return;
    dfs(dep+1,sum,cnt);
    if(cnt==0)
        sum=a[dep];
    else
        sum=(sum)&a[dep];
    dfs(dep+1,sum,cnt+1);
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i-1)
            flag=false;
        mx=max(mx,a[i]);
        s=(i==1 ? a[i]:s&a[i]);
    }
    if(n<=20){
        dfs(1,0,0);
        cout<<ans<<"\n";
    }
    else if(m==1)
        cout<<mx<<"\n";
    else if(m==n)
        cout<<s<<"\n";
    else if(m==2){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
        cout<<ans<<"\n";
    }
    else if(flag)
        cout<<n-m<<"\n";
    else{
        sort(a+1,a+1+n,cmp);
        cout<<a[m]<<"\n";
    }
    return 0;
}
