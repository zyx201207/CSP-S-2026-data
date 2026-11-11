#include <bits/stdc++.h>
using namespace std;

using ll=long long;
int n,m;
ll a[200010];
ll maxx;
ll minn=LLONG_MAX;
ll s[200010];
void dfs(int cnt,int i,ll v){
    if(i>n){
        if(cnt==m){
            maxx=max(maxx,v);
        }
        return ;
    }
    dfs(cnt,i+1,v);
    ll z=v&a[i];
    if(i==1){
        z=a[1];
    }
    dfs(cnt+1,i+1,z);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        minn=min(minn,a[i]);
    }
    s[1]=a[1];
    for(int i = 2;i <= n;i++){
        s[i]=s[i-1]&a[i];
    }
    if(n==m){
        ll ans=a[1]&a[2];
        for(int i = 3;i <= n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        ll maxn=0;
        for(int i = 1;i <= n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
    }
    if(m==2){
        ll maxx=0;
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                ll l=a[i]&a[j];
                maxx=max(maxx,l);
            }
        }
        cout<<maxx;
        return 0;
    }
    if(n<=20){
        dfs(0,1,1);
        cout<<maxx;
        return 0;
    }
    if(m-1==n){
        ll maxxx=0;
        for(int i = 1;i <= n;i++){
            ll x=s[i-1]&((s[n]&s[i])>>1);
            maxxx=max(maxxx,x);
        }
    }
    else{
      int flag=0;
        for(int i = 1;i <= n;i++){
            int x=a[i];
            while(x>=0 && x%2==0){
                x/=2;
                if(x==0)break;
            }
            if(x!=0)flag=1;
        }
        if(flag==0){
            sort(a+1,a+1+n);
            cout<<a[n-m+1];
            return 0;
        }
    }

    return 0;
}
