#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+1;
int c,n,m,d,q,k;
int x,y;
int w[N];
long long a[N][N];
int ch[N];
int main(){
    memset(a,0x3f,sizeof(a));
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x>>y;
            a[i][x]=a[x][i]=y;
        }
    }
    for(int i=1;i<=m;i++) ch[i]=a[i][i];
    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
            for(int k=1;k<=m;k++)
                if(a[i][k]!=0&&a[k][j]!=0)
                    a[j][i]=a[i][j]=min(a[i][j],a[i][k]+ch[k]+a[k][j]);
    while(q--){
        int st,ed;
        cin>>st>>ed;
        cout<<a[st][ed]+w[st]+w[ed]+ch[st]<<endl;
    }
    return 0;
}
