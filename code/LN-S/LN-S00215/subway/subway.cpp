#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500005],k[505],x[100005],y[100005];
ll mn[100005],num[500005];
map<int,map<int,ll> >a,t;
bool ff[500005];
void dfs(ll xx,ll yy,ll pos,ll id,ll sum){
    if(pos==yy){
        mn[id]=min(mn[id],sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[i][1]==pos){
            if(!ff[a[i][2]])dfs(xx,yy,a[i][2],id,sum+t[i][1]+t[i][2]);
        }
        else if(a[i][2]==pos){
            if(!ff[a[i][1]])dfs(xx,yy,a[i][1],id,sum+t[i][1]+t[i][2]);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        if(c>=7&&c<=11){
            memset(ff,0,sizeof(ff));
            dfs(x[i],y[i],x[i],i,w[x[i]]+w[y[i]]);
        }
        else{
            int now=x[i];
            for(int ii=1;ii<=n;ii++){
                bool f=0,fans=0;
                ll shu=0;
                for(int j=2;j<=k[i];j++){
                    if(a[ii][j-1]==now){
                        if(f==0){
                            f=1;
                            mn[i]+=t[ii][j-1];
                            now=a[ii][j];
                            shu=j;
                            if(now==y[i]){
                                fans=1;
                                break;
                            }
                        }
                    }
                }
                if(f==1)mn[i]+=t[ii][shu];
                if(fans==1)break;
            }
        }
        cout<<mn[i]<<"\n";
    }
    return 0;
}
