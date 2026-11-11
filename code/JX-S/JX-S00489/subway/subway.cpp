#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[500005],visl[500005],visp[500005];
struct node{
    int a,t;
}p[5005][5005];
int x,y;
int dfs(int z,int po,int li,int ti){
    if(z==y){
        return ti+p[li][po].t+w[z];
    }
    for(int i=1;i<=k[li];i++){
        if(i!=po&&visp[i]==0) {
            visp[i]=1;
            dfs(p[li][i].a,i,li,ti);
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=li&&visl[i]==0){
            visl[i]=1;
            for(int j=1;j<=k[i];j++){
                if(p[i][j].a==z){
                    dfs(z,j,i,ti+p[po][li].t+p[i][j].t);
                }
            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>p[i][j].a>>p[i][j].t;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        int ans=210000000;
        for(int i=1;i<=max(n,m);i++){
            visl[i]=0;
            visp[i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(p[i][j].a==x){
                    int zzz=dfs(x,j,i,w[x]+p[i][j].t);
                    ans=min(zzz,ans);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
    
