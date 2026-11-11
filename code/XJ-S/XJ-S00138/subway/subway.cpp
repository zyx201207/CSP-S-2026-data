#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
#define int long long
const int N=5e5+10;
int c,n,m,d,q,w[N],k[510],cg[510][510],dis[510][510];
struct Node{
    int a,w;
    friend bool operator<(const Node &i,const Node &j){
        return i.a < j.a;
    }
};
vector<Node> idx[510];
int find(int x,int y){
	int l=0,r=idx[x].size()-1,pos=0;
	while (l<=r){
		int mid=(l+r)>>1;
		if (idx[x][mid].a > y) r=mid-1;
		else if (idx[x][mid].a < y) l=mid+1;
		else return idx[x][mid].w;
	}
	return 0;
}
vector<int> a[N];
vector<int> t[N];
vector<int> sta[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(cg,0x3f,sizeof cg);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++) cin >> w[i];
    for (int i=1,t1,t2;i<=n;i++){
        cin >> k[i];
        cg[i][i]=0;
        for (int j=1;j<=k[i];j++) {
            cin >> t1 >> t2;
            idx[i].push_back((Node){t1,j-1});
            t[i].push_back(t2);
            sta[t1].push_back(i);
        }
        sort(idx[i].begin(),idx[i].end());
    }
    for (int i=1;i<=m;i++)
        for (int j=0,u;j<sta[i].size();j++){
            for (int k=0,v;k<sta[i].size();k++){
            	u=sta[i][j],v=sta[i][k];
                int p=find(sta[i][j],i),q=find(v,i);
                if (u == v) continue;
                cg[u][v]=cg[v][u]=min(cg[u][v],t[u][p]+t[v][q]);
        }
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++){
                cg[i][j]=cg[j][i]=min(cg[i][j],cg[i][k]+cg[k][j]);
            }
    for (int i=1;i<=q;i++) {
        int tot=0x3f3f3f3f3f3f3f3f,x,y;
        cin >> x >> y;
        for (int j=0,u;j<sta[x].size();j++){
            int p=find(sta[x][j],x);
            for (int k=0,v;k<sta[y].size();k++){
            	u=sta[x][j],v=sta[y][k]; 
                int q=find(v,y);
                tot=min(tot,cg[u][v]+t[u][p]+t[v][q]);
        	}
        }
        cout << tot+w[x]+w[y] << '\n';
    }
    return 0;
}

