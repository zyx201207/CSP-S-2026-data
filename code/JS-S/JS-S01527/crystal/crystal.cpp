#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,ans=1,finally_ans=0,lst=0;
ll a[N];
priority_queue<ll,vector<ll>,greater<ll>> q;
queue<ll> poped;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q.push(a[i]);
    }
    lst=q.top();
    while(!q.empty()){
        ll t=q.top();
        poped.push(t);
        q.pop();
        m-=(t-lst)*ans;
        lst=t;
        if(m<0){
            finally_ans=max(ans,finally_ans);
        }
        while(m<0){
            ans--;
            m+=t-poped.front();
            poped.pop();
        }
        ans++;
    }
    cout<<finally_ans;

    return 0;
}