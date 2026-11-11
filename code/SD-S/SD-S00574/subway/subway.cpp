#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500100],k[100100],vv[501][501],b[501],tq[501][501];int c,n,m,d,q;
vector<pair<int,int> >va[501];
vector<pair<int,int> >vb[500100];
vector<int>jt[501];
queue<int>qq;
void db(int l){
	qq.push(l);b[l]=0;
	while(!qq.empty()){
		int xx=qq.front();qq.pop();
		for(int i=0;i<jt[xx].size();i++){
			if(b[jt[xx][i]]<b[xx]+vv[xx][jt[xx][i]])continue;
			b[jt[xx][i]]=b[xx]+vv[xx][jt[xx][i]];qq.push(jt[xx][i]);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,d,t;i<=n;i++){
		cin>>k[i];for(int j=1;j<=k[i];j++){
			cin>>d>>t;
			va[i].push_back(make_pair(d,t));
			vb[d].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vv[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<vb[i].size();j++){
			for(int h=0;h<vb[i].size();h++){
				if(j!=h){
					vv[vb[i][j].first][vb[i][h].first]=
					min(vv[vb[i][j].first][vb[i][h].first],
					vb[i][j].second+vb[i][h].second);
				}
			}
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(vv[i][j]!=1e18&&i!=j){
				jt[i].push_back(j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)b[j]=1e18;
		db(i);
		for(int j=1;j<=n;j++)tq[i][j]=b[j];
	}
	for(int i=1,l,r,minn;i<=q;i++){
		cin>>l>>r;minn=1e18;
		for(int j=0;j<vb[l].size();j++){
			for(int h=0;h<vb[r].size();h++){
//				cout<<vb[l][j].first<<" "<<vb[r][h].first<<" "<<"\n";
				minn=min(minn,w[l]+w[r]+vb[l][j].second+vb[r][h].second+tq[vb[l][j].first][vb[r][h].first]);
			}
		}cout<<minn<<"\n";
	}










	return 0;
}

