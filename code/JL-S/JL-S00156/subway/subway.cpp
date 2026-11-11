#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005],k[505];
vector<int> a[505],t[505];
int mi[505][505],h[500005][505];
vector<int> v[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int x1,x2;
			cin>>x1>>x2;
			a[i].push_back(x1);
			t[i].push_back(x2);
			h[a[i][j]][i]=t[i][j];
			v[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mi[i][j]=1e18;
		}
		mi[i][i]=0;
	}//for(int i=1;i<=m;i++){
		//for(int j=0;j<v[i].size();j++){
			//cout<<v[i][j]<<' ';
//		}
	//	cout<<'\n';
	//}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=0;l<(int)v[a[i][j]].size();l++){
		//		cout<<i<<' '<<v[a[i][j]][l]<<' '<<t[i][j]+h[a[i][j]][v[a[i][j]][l]]<<'\n';
				mi[i][v[a[i][j]][l]]=min(mi[i][v[a[i][j]][l]],t[i][j]+h[a[i][j]][v[a[i][j]][l]]);
			}
		}
	}
	for(int mid=1;mid<=n;mid++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mi[i][j]=min(mi[i][j],mi[i][mid]+mi[mid][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
	//		for(int j=1;j<=n;j++){
		//		cout<<mi[i][j]<<' ';
			//}cout<<'\n';
		//}
	for(int i=1;i<=q;i++){
		int xx,yy,anss=1e18;
		cin>>xx>>yy;
		for(int ww=0;ww<(int)v[xx].size();ww++){
			for(int ee=0;ee<(int)v[yy].size();ee++){
				anss=min(anss,mi[v[xx][ww]][v[yy][ee]]+h[xx][v[xx][ww]]+h[yy][v[yy][ee]]);
			}
		}cout<<anss+w[xx]+w[yy]<<'\n';
	}
	return 0;
}
