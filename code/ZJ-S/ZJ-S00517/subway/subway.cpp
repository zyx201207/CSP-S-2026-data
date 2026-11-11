#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],k[N],dis[505][505];
vector<int>a[N],t[N];
vector<pair<int,int> >sta[M];
signed main(){//freopen,not freeopen,long long!
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        cin>>k[i];
        a[i].resize(k[i]+3);
        t[i].resize(k[i]+3);
        // cout<<1<<endl;
        for(int j=1;j<=k[i];++j){
        	// cout<<1;
            cin>>a[i][j]>>t[i][j];
            sta[a[i][j]].push_back(make_pair(i,t[i][j]));
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            dis[i][j]=LLONG_MAX;
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;++i){
        for(int l1=0;l1<sta[i].size();++l1){
            for(int l2=l1+1;l2<sta[i].size();++l2){
                dis[sta[i][l1].first][sta[i][l2].first]=dis[sta[i][l2].first][sta[i][l1].first]=sta[i][l2].second+sta[i][l1].second;
            }
        }
    }
    for(int i=1;i<=n;++i){
        dis[i][i]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y,mn=LLONG_MAX;
        cin>>x>>y;
        for(pair<int,int> l1:sta[x]){
            for(pair<int,int> l2:sta[y]){
                mn=min(mn,dis[l1.first][l2.first]+l1.second+l2.second);
            }
        }
        cout<<w[x]+w[y]+mn<<endl;
    }
    return 0;
}