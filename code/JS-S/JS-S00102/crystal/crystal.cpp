#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],ans=0,d;
bool ca=1,cb=1;
map<ll,ll>mp;
void dfs(int x,ll y){
    if(x==n+1)return;
    for(ll i=0;i<=y;i++){
        mp[a[x]+y]++;
        ans=max(ans,mp[a[x]]);
        dfs(x+1,y-i);
        mp[a[x]+y]--;
    }
    return;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)ca=0;
        if(i!=1&&i!=2){
            if(a[i]-a[i-1]!=a[i-1]-a[i-2])cb=0;
        }
    }
    if(ca){
        for(int i=1;i<n;i++){
            if(m>=i){
                ans++;
                m-=i;
            }
            else break;
        }
        cout<<ans<<endl;
        return 0;
    }
    if(cb){
        d=a[2]-a[1];
        for(int i=1;i<n;i++){
            if(m>=i*d){
                ans++;
                m-=i*d;
            }
            else break;
        }
        cout<<ans<<endl;
        return 0;
    }
    dfs(1,m);
    cout<<ans<<endl;
    return 0;
}
