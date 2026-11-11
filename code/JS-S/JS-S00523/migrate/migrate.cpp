#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MANX MAXN
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
namespace ylf{ void cat(); }

// 1h 100+100+rand+10
// 4h 100+100+rand+10
// oh no my wc why u give me up
// im so sad 
// um, the difficulty, i think, huanghuanglanzi
// why i guess a fake jielun then lost my 2hours
// i think its so true but it cant ac
// all wrong appears on big examples

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T=1;
    cin>>c>>T;
    while(T--) ylf::cat();
    return 0;
}

namespace ylf{
    void cat(){
        int n,d;
        cin>>n>>d;
        vector<int> x(n+2);
        vector<int> gx(n+2);
        x[0]=-2e18;
        for(int i=1;i<=n;i++) cin>>x[i];
        int cnt=0;
        if(x[3]-x[1]>d&&x[2]-x[1]<=d) gx[1]=1,gx[2]=1;
        if(x[3]-x[2]<=d&&x[3]-x[1]>d) gx[2]=1,gx[3]=1;
        for(int i=3;i<=n;i++){
            if(x[i]-x[i-1]<=d&&x[i]-x[i-2]>d) gx[i]=1,gx[i-1]=1;
            if(x[i]-x[i-2]<=d) gx[i-1]=0;
        }
        for(int i=4;i<=n;i++){
            if(x[i]-x[i-2]<=d&&x[i]-x[i-3]>d&&x[i-1]-x[i-3]<=d){
                int cur=1;
                int l=i-3,r=i;
                int lcnt=1,rcnt=1;
                for(int j=i-4;j>=1;j--){
                    if(x[i]-x[i-2]<=d&&x[i]-x[j]>d&&x[i-1]-x[j]<=d) lcnt++,l--;
                    
                }
                for(int j=i+1;j<=n;j++){
                    if(x[j]-x[i-2]<=d&&x[j]-x[i-3]>d&&x[i-1]-x[i-3]<=d) rcnt++,r++;
                }
                int lm=1,rm=1;
                if(gx[l]==1){
                    int lp=0;
                    for(lp=l-1;lp>=0;lp--){
                        if(gx[lp]!=1) break;
                    }
                    lp++;
                    lm=(l-lp+1);
                }
                if(gx[r]==1){
                    int rp=r;
                    for(;rp<=n+1;r++){
                        if(gx[rp]==1) break;
                    }
                    rm=(rp-r+1);
                }
                cur=lcnt*rm+lm*rcnt;
                cur--;
                cnt+=cur;
            }
        }
        cout<<cnt<<"\n";
       // for(int i=1;i<=n;i++) cout<<gx[i]<<' ';
    }
}