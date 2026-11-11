#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+5;
const int lgN = 25;
int c,T;
int n,d;
int x[N];
int nxt[N][lgN];
bool ck(int l,int r){
    return x[r]-x[l]<=d;
}
int ef(int l,int r){
    int al=l;
    int ll=l;
    if(x[n]-x[l]<=d)
        return n+1;
    while(l<=r){
        int mid=(l+r)>>1;
        bool b=ck(ll,mid);
        if(b)
            al=max(al,mid);
        if(b)
            l=mid+1;
        else
            r=mid-1;
    }
    return al;
}
int dis(int a,int b){
    int s=0;
    for(int i=lgN-1;i>=0;i--){
        if(nxt[a][i]==-1)
            continue;
        if(a!=b&&nxt[a][i]<=b){
            a=nxt[a][i];
            s+=(1<<i);
        }
    }
    if(a!=b)
        s++;
    return s;
}
int minn[N];
int rt[N];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        memset(nxt,-1,sizeof nxt);
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        for(int i=1;i<=n;i++)
            nxt[i][0]=ef(i,n);
        rt[n+1]=n+2;
        rt[n+2]=n+3;
        for(int i=n;i;i--){
            rt[i]=i+1;
            if(nxt[i][0]==i+1)
                rt[i]=rt[i+1];
        }
        
        for(int j=1;j<lgN;j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
                nxt[i][j]=nxt[nxt[i][j-1]][j-1];
        for(int i=1;i<=n;i++){
            for(int j=rt[rt[i]];j<=n;j++){
                int d_=dis(i,j),d__=dis(rt[i],j)+dis(i,rt[i]),d___=dis(rt[rt[i]],j)+dis(rt[i],rt[rt[i]]);
                if(d_==d__&&(d_!=d___||rt[rt[i]]==nxt[i][0]))
                    ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//mo cai lian dong bang bang? zhen de jia de?
//wo qu, zhen lian dong le.

//csp-s hun le wu nian le, bu liu ji ming nian dou shang da xue le, mei ji hui zai da le.
//zai ci ming ji wo de (shang gong) qing chun
//So, tell me, where should I go?
//sayonara~