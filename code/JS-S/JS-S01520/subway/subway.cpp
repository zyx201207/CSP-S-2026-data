#include<bits/stdc++.h>
using namespace std;
#define int long long


int c,n,m,d,q;
int w[500005]={};
int k[505]={};

vector<int> a[505]={};
vector<int> t[505]={};

int dis[505][505]={};

vector<int> nt[500005]={};
vector<int> nto[500005]={};


const int inf=1e18;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);


    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
        cin>>k[i];

        a[i].resize(k[i]+1);
        t[i].resize(k[i]+1);
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            nto[a[i][j]].push_back(i);
            nt[a[i][j]].push_back(t[i][j]);
        }

    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=inf;
        }
    }

    for(int i=1;i<=m;i++){
        int num=nto[i].size();

        for(int l=0;l<num;l++){
            for(int r=l+1;r<num;r++){
                dis[nto[i][l]][nto[i][r]]=min(dis[nto[i][l]][nto[i][r]],nt[i][l]+nt[i][r]);
                dis[nto[i][r]][nto[i][l]]=min(dis[nto[i][r]][nto[i][l]],nt[i][l]+nt[i][r]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }

    for(int t=1;t<=n;t++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][t]+dis[t][j]);
            }
        }
    }

    for(int t=1;t<=q;t++){
        int x;
        int y;
        cin>>x>>y;

        int ans=inf;
        for(int l=0;l<nto[x].size();l++){
            for(int r=0;r<nto[y].size();r++){
                ans=min(ans,w[x]+w[y]+nt[x][l]+nt[y][r]+dis[nto[x][l]][nto[y][r]]);
            }
        }

        cout<<ans<<endl;
    }

    return 0;

}