#include<bits/stdc++.h>
using namespace std;

const int maxn=2e6+10;

long long arr[maxn];
int nxt[maxn],prv[maxn][5];
bool vis[maxn];
int sumn=0;
void solve(int id){
    long long n,d;
    scanf("%lld%lld",&n,&d);
    sumn+=n;
    // if(id==4) fprintf(stderr,"%lld %lld\n",n,d);
    for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
    // if(id==4){
    //     for(int i=1;i<=n;i++) fprintf(stderr,"%lld ",arr[i]);
    //     fprintf(stderr,"\n");
    //     return;
    // }
    arr[n+1]=1.1e18;
    nxt[n+1]=0;
    for(int i=0;i<=n+1;i++) prv[i][0]=prv[i][1]=prv[i][2]=prv[i][3]=prv[i][4]=0;
    for(int i=1;i<=n;i++){
        nxt[i]=upper_bound(arr+1,arr+1+n,arr[i]+d)-arr-1;
        vis[i]=(nxt[i]==i);
    }
    long long sum=0;
    for(int i=n;i>=1;i--){
        // if(vis[i]) continue;
        if(vis[nxt[i]]) continue;
        int p=nxt[i],q=nxt[p];
        if(p-i==1){
            if(q-p==1){
                prv[p][0]=prv[q][0],prv[p][1]=prv[q][1]+1;
            }else{
                prv[p][0]=prv[q][2],prv[p][1]=prv[q][4]+q-p;
            }
        }else{
            int r=nxt[p-1],l=max(p+1,nxt[p-2]+1);
            if(l>q) continue;
            if(q-p==1){
                if(q<=r){
                    prv[p][2]=prv[q][1]+(r-l+1);
                }else{
                    prv[p][2]=prv[p][3]=prv[q][0],prv[p][4]=prv[q][1]+1;
                }
            }else{
                if(q<=r){
                    prv[p][2]=prv[q][4]+r-l+1;
                }else if(q-1<=r){
                    prv[p][2]=prv[q][3]+r-l+1;
                    prv[p][3]=prv[q][3];
                    prv[p][4]=prv[q][4]+1;
                }else{
                    prv[p][2]=prv[q][2]+r-l+1;
                    prv[p][3]=prv[q][2];
                    prv[p][4]=prv[q][4]+(q-r);
                }
            }
        }
        if(p-i==1){
            sum+=prv[p][0];
        }else{
            sum+=prv[p][2];
        }
        // fprintf(stderr,"%d %d %d %d %d %d %d\n",p,prv[p][0],prv[p][1],prv[p][2],prv[p][3],prv[p][4],sum);
    }
    printf("%lld\n",sum);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T,cnt=0;
    scanf("%d%d",&c,&T);
    while(T--){
        solve(++cnt);
    }
}