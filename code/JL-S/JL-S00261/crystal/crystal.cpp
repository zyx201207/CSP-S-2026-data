#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    queue<ll> q;
    q.push(a[1]);
    ll ans=1,cnt=0;
    for(int i=2;i<=n;i++){

        ans=max(ans,(ll)q.size());
        if((a[i]-a[i-1])*q.size()+cnt<=m){
            cnt+=(a[i]-a[i-1])*q.size();
            q.push(a[i]);

        }else{
            while(!q.empty()&&cnt+(a[i]-a[i-1])*q.size()>m){
                cnt-=(a[i-1]-q.front());
                q.pop();

            }
            if(!q.empty()){
                cnt+=(a[i]-a[i-1])*q.size();
            }
            q.push(a[i]);
        }
    }
    cout<<max(ans,(ll)q.size())<<'\n';
    return 0;
}
