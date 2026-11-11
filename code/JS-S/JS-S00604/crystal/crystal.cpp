#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a); i<=(b); ++i)
#define per(i,a,b) for(int i=(a); i>=(b); --i)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,int> PLI;
const int MAXN = 5e5+10;

queue<PLI> q1;
ll q2[MAXN],v[MAXN];
int num[MAXN];
int n;
ll m;
ll a[MAXN];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rep(i,1,n){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int cnt1=0;
    rep(i,1,n){
        if(i!=1&&a[i]!=a[i-1]){
            q1.push({a[i-1],cnt1});
            cnt1=1;
        }else{
            ++cnt1;
        }
    }
    q1.push({a[n],cnt1});
    ll sum=0;
    int x=1,y=0,cnt2=0;
    int ans = 0;
    v[0]=1e18+10;
    while(q1.size()){
        auto now = q1.front();q1.pop();
        while(now.first*cnt2-sum>m){
            cnt2-=num[x];
            sum-=q2[x++];
        }
        ans=max(ans,now.second+cnt2+(int)((m-(now.first*cnt2-sum))/(now.first-v[x-1])));
        cnt2+= now.second;
        q2[++y]=now.first*now.second;
        v[y]=now.first;num[y]=now.second;
        sum+=now.first*now.second;
    }
    cout<<ans<<'\n';
    return 0;
}