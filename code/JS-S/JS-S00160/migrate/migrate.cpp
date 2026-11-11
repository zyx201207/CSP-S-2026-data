#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
int c,t,n;
ll d,a[N],cnt,ans;
void dfs(int s,int e,int len,int k){
    if(s==e){
        if(len==k) cnt++;
        //cout<<len<<"\n";
        return;
    }
    for(int i=s+1;i<=e;i++){
        if(a[i]-a[s]<=d) dfs(i,e,len+1,k);
    }
}
bool check(int s,int e){
    ll k=(a[e]-a[s]-1)/d+1;
    //cout<<k<<" ";
    cnt=0;
    dfs(s,e,0,k);
    if(cnt==2) return true;
    else return false;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d) continue;
                //cout<<i<<" "<<j<<"\n";
                if(check(i,j)) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
