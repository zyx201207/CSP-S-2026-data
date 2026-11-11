#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505,K=5e5+5,Q=1e5+5;
int w[M];
int k[N];
int a[N][K];
int t[N][K];
int x[Q];
int y[Q];
vector<int> tmp[M];
vector<int> tmpt[M];
int ovo[N][N];
int c,n,m,d,q;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ovo[i][j]=INT_MAX;
        }
    }
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int kmax=0;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        kmax=max(kmax,k[i]);
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            tmp[a[i][j]].push_back(i);
            tmpt[a[i][j]].push_back(t[i][j]);
        }
    }
    for(int i=1;i<=m;i++){
        int len=tmp[i].size();
        for(int j=0;j<len;j++){
            for(int k=j+1;k<len;k++){
                ovo[tmp[i][j]][tmp[i][k]]=min(ovo[tmp[i][j]][tmp[i][k]],tmpt[i][j]+tmpt[i][k]);
                ovo[tmp[i][k]][tmp[i][j]]=min(ovo[tmp[i][k]][tmp[i][j]],tmpt[i][j]+tmpt[i][k]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        int cnt=w[x[i]]+w[y[i]];
        int ans=INT_MAX;
        int lenj=tmp[x[i]].size(),lenk=tmp[y[i]].size();
        int an[N][N];
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                an[j][k]=ovo[j][k];
            }
        }
        for(int j=0;j<lenj;j++){
            for(int k=0;k<lenk;k++){
                for(int l=1;l<=n;l++){
                    if(an[tmp[x[i]][j]][l]!=INT_MAX&&an[l][tmp[y[i]][k]]!=INT_MAX){
                        an[tmp[x[i]][j]][tmp[y[i]][k]]=min(an[tmp[x[i]][j]][tmp[y[i]][k]],an[tmp[x[i]][j]][l]+an[l][tmp[y[i]][k]]);
                    }
                }
            }
        }
        for(int j=0;j<lenj;j++){
            for(int k=0;k<lenk;k++){
                if(an[tmp[x[i]][j]][tmp[y[i]][k]]!=INT_MAX) ans=min(ans,tmpt[x[i]][j]+tmpt[y[i]][k]+cnt+an[tmp[x[i]][j]][tmp[y[i]][k]]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
