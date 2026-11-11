#include <bits/stdc++.h>
using namespace std;
const int N=15000;
int c,n,m,d,q;
int w[N];
int k[1005];
int a[N][N],p[N][N];
int x[N],y[N];
int ll,ss;
int ans=0;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(p,0,sizeof(p));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>p[i][j];
        }
    }
    for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
    for(int i=1;i<=q;i++){
        int tot=w[x[i]]+w[y[i]];
        int l1=0,minn=1e9;
        for(int a=x[i];a<=y[i];a++){
            for(int i=1;i<=d;i++){
                if(l1==i){
                    if(p[l1][a]<minn){
                        minn=p[l1][a+1];
                        l1=i;
                    }
                }
                else{
                    if(p[i][a]+p[i][a+1]<minn){
                        minn=p[i][a]+p[i][a+1];
                        l1=i;
                    }
                }
            }
            if(a=ss) ll=l1;
            ans+=minn;
        }
        ans=0;
        ss=x[i];
        tot+=ans+p[ll][ss];
        cout<<tot<<endl;
    }
}
