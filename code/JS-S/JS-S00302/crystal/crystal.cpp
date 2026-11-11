#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,ans,cnt,v,a[N],cz[N];
bool eq;
struct node{
    ll idx,cntx,vx;
}flag[N];

bool cpp(node x,node y){
    return x.cntx>y.cntx;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        flag[i].cntx++;
        flag[i].idx=i;
        flag[i].vx=a[i];
    }
    ll d=a[2]-a[1];
    for(int i=2;i<=n;++i){
        if(a[i]-a[i-1]==d) eq=1;
    }
    if(eq){
        if(m/d>0) cout<<m/d+1;
        else cout<<0;
        return 0;
    }
    sort(flag+1,flag+n+1,cpp);
    v=flag[1].vx;
    for(int i=1;i<=n;++i){
        if(a[i]>v) continue;
        cz[flag[i].idx]=v-a[i];
    }
    sort(cz+1,cz+n+1);
    ll k=1;
    while(k<=n&&m>0){
        if(m>=flag[flag[k].idx].cntx*cz[k]){
            ans+=flag[flag[k].idx].cntx;
            m-=flag[flag[k].idx].cntx*cz[k];
        }
        else{
            ans+=m/cz[k];
            break;
        }
        k++;
    }
    cout<<ans;
    return 0;
}
