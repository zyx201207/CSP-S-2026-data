#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pp;
long long n,m,q;
long long w[500505],len[505][505];
vector<pp> a[500505];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(len,0x3f,sizeof(len));
    cin>>n>>n>>m>>q>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            long long v,l;
            cin>>v>>l;
            a[m+i].push_back({l,v});
            a[v].push_back({l,m+i});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<a[i].size();j++){
            for(int k=j;k<a[i].size();k++){
                len[a[i][j].second-m][a[i][k].second-m]=a[i][j].first+a[i][k].first;
                //cout<<i<<" "<<j<<" "<<k<<" "<<a[i][j].second-m<<" "<<a[i][j].first<<" "<<a[i][k].second-m<<" "<<a[i][k].first<<"\n";
                len[a[i][k].second-m][a[i][j].second-m]=len[a[i][j].second-m][a[i][k].second-m];
            }
        }
    }
    for(int i=1;i<=n;i++)len[i][i]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
				//cout<<i<<" "<<j<<" "<<k<<" "<<len[i][j]<<" "<<len[i][k]<<" "<<len[k][j]<<"\n";
                len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
            }
        }
    }/*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cout<<len[i][j]<<" ";
    }
    //cout<<endl<<a[2][1].second<<"\n";*/
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        long long minn=LONG_LONG_MAX;
        for(int j=0;j<a[u].size();j++){
            for(int k=0;k<a[v].size();k++){
				//cout<<a[u][j].second-m<<" "<<a[v][k].second-m<<" "<<len[a[u][j].second-m][a[v][k].second-m]<<" "<<a[u][j].first<<" "<<a[v][k].first<<"\n";
                minn=min(minn,len[a[u][j].second-m][a[v][k].second-m]+a[u][j].first+a[v][k].first);
            }
        }
        cout<<minn+w[u]+w[v]<<"\n";
    }
    return 0;
}
