#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N =5e5;
ll n=0,m=0;
int a[N+5],ans[N+5],q[N+5],cnt[N+5];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(ll i=1;i<=n;i++){
        if(cnt[a[i]]==1){
            q[i]=q[i-1]+1+ans[a[i]];
        }
        else{
            q[i]=0;
        }
        ans[a[i]]+=q[i-1]+1;
        cnt[a[i]]--;
    }
    ans[a[n]]=n;
    for(ll i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
