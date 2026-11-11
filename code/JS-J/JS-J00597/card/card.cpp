#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans[300005];
bool is[500005];
struct Node{
    ll x;
    ll index;
};
Node a[500005];
bool cmp(Node b,Node c){
    return b.x<c.x;
}
ll cheak(ll goal,Node a[]){
    ll l=1,r=goal-1,mid;
    ll ans=0x3f3f3f3f;
    sort(a+1,a+goal+1,cmp);
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid].x<a[goal].x){
            l=mid;
        }
        else if(a[mid].x>a[goal].x){
            r=mid-1;
        }
        else{
            ans=min(ans,a[mid].index);
        }
    }
    if(ans=0x3f3f3f3f) ans=0;
    return ans;
}
void fugai(ll st,ll en){
    for(int i=st;i<=en;i++){
        is[i]=0;
    }
}
void answ(int st){
    for(int i=st;i<=n;i++){
        if(is[a[i].index]!=0){
            ans[a[i].index]++;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
    }
    for(ll i=1;i<=n;i++){
        a[i].index=i;

    }
    for(ll j=1;j<=n;j++){
        memset(is,true,sizeof(is));
        for(ll i=j;i<=n;i++){
            ll t=cheak(i,a);
            if(t!=0){
                fugai(t,i);
            }
        }
        answ(j);
    }
    for(int i=1;i<=m;i++) cout<<ans[i];
    return 0;
}
