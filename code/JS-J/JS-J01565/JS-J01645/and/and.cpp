#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[200005],ans=0,sum1,cnt1,b[10];
bool flag=0;
int ta[30]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
void dfs(ll u,ll cnt,ll sum){
    if(cnt==m){
        ans=max(ans,sum);
        return;
    }
    for(int i=u+1;i<=n-m+cnt+1;i++){
        dfs(i,cnt+1,sum&a[i]);
    }
}
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=20;i++)if(n==ta[i])flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=20;j++){
            if(a[i]+1==ta[j])cnt1++,j=21;
        }
        ans=max(ans,a[i]);
        if(i==1)sum1=a[i];
        sum1&=a[i];
    }
    if(m==1){
        cout<<ans;
        return 0;
    }
    else if(m==n){
        cout<<sum1;
        return 0;
    }
    else if(m==2){
        ll x=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                x=max(x,a[i]&a[j]);
            }
        }
        cout<<x;
        return 0;
    }
    else if(n<=20){
        ans=0;
        for(int i=1;i<=n-m+1;i++){
            dfs(i,1,a[i]);
        }
        cout<<ans;
        return 0;
    }
    else if(m==n-1){
        ll x=0;
        for(int i=1;i<=n;i++){
            ll y=(sum1&a[i])|(a[i]^(sum1|a[i]));
            x=max(x,y);
        }
        cout<<x;
        return 0;
    }
    else if(cnt1==n){
        sort(a+1,a+1+n,cmp);
        cout<<a[m];
        return 0;
    }
    else if(ans==4){
        for(int i=1;i<=n;i++)b[a[i]]++;
        if(m<=b[4]){
            cout<<4;
            return 0;
        }
        else if(m<=b[3]){
            cout<<3;
            return 0;
        }
        else if(m<=b[2]+b[3]){
            cout<<2;
            return 0;
        }
        else if(m<=b[1]+b[3]){
            cout<<1;
            return 0;
        }
        else {
            cout<<0;
            return 0;
        }
    }
    else{
        ans=0;
        for(int i=1;i<=n-m+1;i++){
            dfs(i,1,a[i]);
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
