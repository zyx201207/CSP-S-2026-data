#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll INF=1e16+10;
ll a[N];
int n,m;
ll ans=-INF;
ll cnt=1;
ll maxn=-INF;
vector<ll> vec;
void backTracking(int k){
    if(vec.size()==m){
        cnt=vec[0];
        for(int i=1;i<m;i++){
            cnt=cnt&vec[i];
        }
        ans=max(ans,cnt);
        return ;
    }
    for(int i=k;i<=n;i++){
        vec.push_back(a[i]);
        backTracking(i+1);
        vec.pop_back();
    }
}
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(m==1){
        for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
        printf("%lld",maxn);
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        printf("%lld",ans);
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;i<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        printf("%lld",maxn);
        return 0;
    }
    if(m==n-1){
        ans=a[2];
        for(int i=3;i<=n;i++){
            ans=ans&a[i];
        }
        maxn=max(maxn,ans);
        for(int i=2;i<=n;i++){
            ans=a[1];
            for(int j=2;j<=n;j++){
                if(j==i) continue;
                ans=ans&a[j];
            }
            maxn=max(maxn,ans);
        }
        printf("%lld",maxn);
        return 0;
    }
    if(n>=200 && n<=2e5+10){
        sort(a+1,a+n+1,cmp);
        printf("%lld",a[m]);
        return 0;
    }
    backTracking(1);
    printf("%lld",ans);
    return 0;
}
