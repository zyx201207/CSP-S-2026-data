#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,m,a[N],cnt[N][35],vis[35],maxn,isok[N],s,ans=INT_MAX,c,e[N];
bool cmp(ll x,ll y){
    return x>y;
}

void f(ll i){
    ll x[vis[i]+1]={},sum=1;
    for(int j=1;j<=n;j++){
        if(!cnt[j][i]&&isok[j]){
            x[sum++]=1;
        }
        if(s-sum<m){
            return;
        }
    }
    for(int j=1;j<=sum;j++){
        isok[x[j]]=0;
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    ll q=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q=max(q,a[i]);
    }
    if(m==1){
        cout<<q;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        ll x=a[i],num=0;
        while(x){
            if(x&1){
                cnt[i][num]++;
                vis[num]++;
            }
            num++;
            x>>=1;
        }
        maxn=max(maxn,num-1);
    }
    for(ll i=maxn;i>=0;i--){
        if(vis[i]<m){
            continue;
        }
        if(!c){
            c=1;
            for(ll j=1;j<=n;j++){
                if(cnt[j][i]){
                    isok[j]=1;
                    s++;
                }
            }
        }else{
            f(i);
        }
    }
    if(!c){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(isok[i]){
            ans&=a[i];
        }
    }
    cout<<ans;
    return 0;
}
