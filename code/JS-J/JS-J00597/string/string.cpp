#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ind,rest,ri,xyj;
ll ans=0;
int cnt[200005];
char a[200005];
void solve(int x,int y){
    if(cnt[x]<=cnt[y]) swap(x,y);
    if(rest==0){
        if(a[x]!=a[y]){
            rest=cnt[x]-cnt[y];
            ri=x;
            ans+=cnt[x];
            return;
        }
        else{
            rest=cnt[x]-cnt[y];
            ri=x;
        }
    }
    else{cnt[y]-=rest;
    ans+=rest;
    if(rest!=0) xyj=rest;
        if(cnt[y]<0){
            y--;ind--;
        }
        if(a[x]!=a[y]){
            rest=cnt[x]-cnt[y];
            ri=x;
            ans+=cnt[x];
            return;
        }
        else{
            rest=cnt[x]-cnt[y];
            ri=x;uyuct
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cnt[i]>>a[i];
    }
    for(int i=1;i<=n/2+1;i++){
        ind=n+1-i;
        solve(i,ind);
    }

    cout<<ans-xyj;
    return 0;
}
