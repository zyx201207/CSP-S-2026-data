#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,k,tmp,tmpp,ans;
int w[20010],a[20010][501],xianlu[501][20010],cst[20010][501],st,en;
bool b[20010][501];
struct node{
    int pos,dis,xl,ltr;
    bool operator<(const node &x)const{
        return x.dis<dis;
    }
};
priority_queue<node> qq;

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        xianlu[i][0]=k;
        for(int j=1;j<=k;j++){
            cin>>tmp>>tmpp;
            a[tmp][i]=1;
            cst[tmp][i]=tmpp;
            xianlu[i][j]=tmp;
        }
    }
    for(int kkk=1;kkk<=q;kkk++)
    {
        memset(b,0,sizeof(b));
        ans=0;
        cin>>st>>en;
        ans+=w[st]+w[en];
        b[st][0]=1;
        for(int i=1;i<=n;i++){
            if(a[st][i]!=0){
                qq.push((node){st,cst[st][i],i,1});
                b[st][i]=1;
            }
        }
        while(qq.top().pos!=en){
            node op=qq.top();
            qq.pop();
            if(op.ltr==1){
                int opp;
                for(int i=1;i<=xianlu[op.xl][0];i++){
                    opp=xianlu[op.xl][i];
                    if(b[opp][op.xl]==0&&b[opp][0]==0){
                        qq.push((node){opp,op.dis+cst[opp][op.xl],0,0});
                        b[opp][0]=b[opp][op.xl]=1;
                    }
                }
            }
            else{
                for(int i=1;i<=n;i++){
                    if(a[op.pos][i]!=0&&b[op.pos][i]==0){
                        qq.push((node){op.pos,op.dis+cst[op.pos][i],i,1});
                        b[op.pos][i]=1;
                    }
                }
            }
        }
        ans+=qq.top().dis;
        cout<<ans<<"\n";
        while(!qq.empty())qq.pop();
    }
    return 0;

}
