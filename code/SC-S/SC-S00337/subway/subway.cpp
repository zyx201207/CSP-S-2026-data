#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int t[505][50005];
int a[505][50005];
int x[100005];
int y[100005];
int k[505];
int pd=1;
int ppd=1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2){
			ppd=0;
		}
		int la,lt;
		for(int j=1;j<=2*k[i];j++){
			cin>>la>>lt;
			a[i][la]=1;
			t[i][j]=lt;
			if(t[i][j]!=t[1][1]){
				pd=0;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	int ans=500000;
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;i++){
			if(a[j][y[i]]!=0){
				ans=min(ans,t[j][x[i]]+t[j][y[i]]);
			}
		}
		cout<<w[x[i]]+ans+w[y[i]]<<'\n';
	}
	return 0;
//	
//	--------------------------------
//	Process exited after 0.02934 seconds with return value 0 (0 ms cpu time, 201512 KB mem used).
//	
//	Press ANY key to exit...
//  我再也不坐列车了
//  地铁站口--->站厅--->站台--->线路--->站厅--->站台--->线路--->......--->线路--->站厅--->地铁口
}
