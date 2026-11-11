#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxn;
struct Node{
    ll a;
    ll yu;
}newn[200005];
bool cmp(Node a,Node b){
    if(a.yu==b.yu){
        a.a>b.a;
    }
    else {
        return a.yu>b.yu;
    }
}
ll kand(ll x){
    ll ans=0;
    while(x>0){
        ans+=x&1;
        x>>=1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>newn[i].a;
        newn[i].yu=kand(newn[i].a);
    }
    sort(newn+1,newn+n+1,cmp);
    ll cnt=newn[1].a;

    for(int i=2;i<=m;i++){
        cnt=cnt&newn[i].a;
    }
    cout<<cnt;
    return 0;
}
