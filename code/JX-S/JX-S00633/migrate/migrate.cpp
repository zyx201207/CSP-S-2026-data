#include<iostream>
//#include<iomanip>
#include<vector>
using namespace std;
#define ll long long
#define endl '\n'
//#define inf 0x3f3f3f3f
int c,t;

int n;
ll d;
ll cost[(int)2e5+5];
ll memo[(int)2e3+5][(int)2e3+5];
ll dist(ll a,ll b){return cost[b]-cost[a];}
ll f(ll a,ll b,ll des){
    int cnt=0;
    if(b==a)return 0;
    if(b==a+1)return dist(a,a+1);
    if(memo[a][b])return memo[a][b];
    ll ans=dist(a,b);
    for(int i=1;i<b-a;i++){
        ll k=f(a,a+i,des)+f(a+i,b,-1);
        if(ans==k)cnt++;
        else ans=min(ans,k);
    }
    memo[a][b]=ans;
    if(b==des)return (cnt==2);
    return ans;
}
void solve(){
    int cnt=0;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){;
            if(f(i,j,j))cnt++;
        }
    }
    cout<<cnt<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    for(int i=1;i<=t;i++)solve();
    return 0;
}
