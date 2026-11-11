#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N=2000010;

int n;
ll k;
ll a[N],d[N],c[N];

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++) d[j]=INT_MAX,c[j]=0;
        d[i]=0,c[i]=1;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int j=upper_bound(a+x+1,a+n+1,a[x]+k)-a-1;j>=x;j--)
                if(d[j]==INT_MAX) d[j]=d[x]+1,c[j]=c[x],q.push(j);
                else if(d[j]==d[x]+1) c[j]+=c[x];
                else break;
        }
        for(int j=i;j<=n;j++) ans+=(c[j]==2);//,cout<<c[j]<<" "<<d[j]<<"\n";
//        cout<<"\n";
    }
    cout<<ans<<"\n";
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    int c;
    cin>>c>>t;
    while(t--)solve();
}
