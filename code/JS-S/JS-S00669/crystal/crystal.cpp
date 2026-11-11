#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int MAXN=1e6+7;
int n;
ll m,a[MAXN];
ll nxt[MAXN],up[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        nxt[i]=1+i;
        up[i]=i-1;
    }
    up[1]=0;
    nxt[n]=inf;
    nxt[0]=1;
    up[n+1]=n;
    sort(a+1,a+n+1);
    ll ed=n;
    for(int i=1;i<=n;i++){
        ll le=inf,p=inf;
        //cerr<<inf;
        for(ll j=nxt[0];j<=up[ed+1];j=nxt[j]){

            if(nxt[j]<=up[ed+1]&&a[nxt[j]]-a[j]<le){
                p=j;

                le=a[nxt[j]]-a[j];
            }
        }
        //cerr<<endl<<nxt[0]<<' '<<ed<<' '<<le<<endl;
        if(m<le)break;
        if(p!=inf){
            m-=le;
            nxt[ed+1]=ed+2;
            nxt[ed]=ed+1;
            up[ed+1]=ed;
            up[ed+2]=ed+1;
            ed++;
            a[ed]=2*a[nxt[p]];
            a[p]=a[nxt[p]]=inf;
            nxt[up[p]]=nxt[nxt[p]];
            up[nxt[nxt[p]]]=up[p];
            ll g=ed;
            while(up[g]>=nxt[0]&&a[g]<a[up[g]])swap(a[g],a[up[g]]),g=up[g];
        }
    }
    int cnt=0;
    for(int j=1;j<=ed;j++){
        //cerr<<a[j]<<' ';
        cnt+=a[j]!=inf;
    }
    cout<<n-cnt;


    return 0;
}
