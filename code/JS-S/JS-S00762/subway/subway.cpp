#include <bits/stdc++.h>
using namespace std;
vector<long long> a[505],t[505];
vector<pair<int,long long> > s[505];
long long dis[505][505];
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<long long> w,k;
    for (int i=0;i<m;i++){
        int aaaa;
        cin>>aaaa;
        w.push_back(aaaa);
    }
    memset(dis,0x3f,sizeof dis);
    for (int i=0;i<n;i++){
        int aaaa;
        cin>>aaaa;
        k.push_back(aaaa);
        for (int j=0;j<aaaa*2;j++){
            long long bbbb;
            cin>>bbbb;
            if (j%2==0){
                a[i].push_back(bbbb);
            }
            else{
                t[i].push_back(bbbb);
            }
        }
        for (int j=0;j<aaaa;j++){
            s[a[i][j]].push_back(make_pair(i,t[i][j]));
        }
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<s[i].size();j++){
            for (int l=j+1;l<s[i].size();l++){
                dis[s[i][j].first][s[i][l].first]=min(dis[s[i][j].first][s[i][l].first],s[i][j].second+s[i][l].second);
                dis[s[i][l].first][s[i][j].first]=min(dis[s[i][l].first][s[i][j].first],s[i][j].second+s[i][l].second);
            }
        }
    }
    for (int i=0;i<n;i++){
        dis[i][i]=0;
    }
    for (int l=0;l<n;l++){
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
                dis[j][i]=min(dis[j][i],dis[j][l]+dis[l][i]);
            }
        }
    }
    for (int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        long long ans=1234567890123456789ll;
        for (int j=0;j<s[x].size();j++){
            for (int l=0;l<s[y].size();l++){
                ans=min(ans,dis[s[x][j].first][s[y][l].first]+w[x-1]+w[y-1]+s[x][j].second+s[y][l].second);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
