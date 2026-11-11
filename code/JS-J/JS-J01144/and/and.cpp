#include<bits/stdc++.h>
using namespace std;
int n,m;
long long s,maxn,ans;
long long a[200010],dp[200010];
bool vis[200010];
void work(int y,long long k){
    if(y==m){
        if(k>ans) ans=k;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            work(y+1,(k&a[i]));
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s=s&a[i];
        if(a[i]>maxn) maxn=a[i];
    }
    if(n==m){
        cout<<s<<endl;
        return 0;
    }
    if(m==1){
        cout<<maxn<<endl;
        return 0;
    }
    if(m==2){
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                if((a[i]&a[j])>=ans) ans=(a[i]&a[j]);
        cout<<ans<<endl;
        return 0;
    }
    if(n<=20){
        work(0,1111111111);
        cout<<ans<<endl;
        return 0;
    }
    if(maxn<4){
        cout<<3<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    cout<<a[n-m+1]<<endl;
    return 0;
}
