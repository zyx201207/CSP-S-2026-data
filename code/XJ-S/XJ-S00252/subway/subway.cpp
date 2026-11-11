#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX=1e18;
const int MAXN=5e5+10;
int read(){
    int ret=0,sgn=0,ch=getchar_unlocked();
    while(ch>'9'||ch<'0')sgn |= ch=='-',ch=getchar();
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar_unlocked();
    return sgn ?-ret:ret;
}
int C,n,m,d,Q;
//vector<vector<int> >g(MAXN),c(MAXN);
vector<vector<int> >a(500),t(500);
int w[MAXN],siz[MAXN];
ll dist[512][512];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //ios::sync_with_stdio(false);
    C=read(),m=read(),n=read(),d=read(),Q=read();
    for(int i=1;i<=n;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)dist[i][j]=MAX;
    }
    for(int i=1;i<=n;i++)dist[i][i]=0;
    for(int i=1;i<=m;i++){
        cin>>siz[i];
        for(int j=1;j<=siz[i];j++){
            a[i].push_back(read());
            t[i].push_back(read());
        }
        
    }
    for(int i=1;i<=m;i++)
        for(int j=0;j<siz[i];j++){
            for(int q=j+1;q<siz[i];q++){
                dist[a[i][j]][a[i][q]]=dist[a[i][q]][a[i][j]]=t[i][j]+t[i][q];
            }
        }
    
    for(int mk=1;mk<=m;mk++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j]!=MAX&&i!=j){
                    for(int q=1;q<=n;q++){
                        if(dist[i][j]+dist[j][q]<dist[i][q]&&dist[j][q]!=MAX)dist[i][q]=dist[i][j]+dist[j][q];
                    }
                }
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cout<<dist[i][j]<<" ";
        cout<<"\n";
    }*/
    while(Q--){
        int l,r;
        l=read(),r=read();
        cout<<dist[l][r]+w[l]+w[r]<<"\n";

    }
    return 0;
}