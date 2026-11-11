#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200010;
ll a[N],tmp[N];
bool cnt[N];
vector<ll>mp[35];
map<ll,ll>p;
ll ret,n,m;
void dfs(ll x,ll y){
    if(y==m){
    	ll z=1,s=0;
        for(int j=0;j<=30;j++){
            if(x & (z<<j)){
                s++;
            }
        }
        ret=max(ret,s);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!cnt[i]){
            cnt[i]=true;
            dfs(x&a[i],y+1);
            cnt[i]=false;
        }
    }
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int maxx=-1,rett=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ll x=1,ww=0;
        for(int j=0;j<=30;j++){
            if(a[i] & (x<<j)){
                mp[j].push_back(a[i]);
                ww++;
            }
        }
        if(ww>maxx) maxx=ww,rett=a[i];
    }
    if(m==1){
        cout<<rett;
        return 0;
    }
    if(m==n){
        ll reet=a[1];
        for(int i=1;i<=n;i++){
            reet&=a[i];
        }
        cout<<reet;
        return 0;
    }
    dfs(2147483647,0);
    cout<<ret;
    return 0;
} 
