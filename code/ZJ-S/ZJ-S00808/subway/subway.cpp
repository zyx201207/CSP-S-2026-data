#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=10005;
struct node{
	int to,tim;
};
int c,n,m,d,q,w[M],k[M],f[M][M];
vector<node > v[M];
void floyd(){
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=1;k<j;k++){
				f[i][j]=min(f[i][j],f[j-k][i]+f[j][j-k]);
			}
			f[j][i]=f[i][j];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		f[i][i]=0;
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		vector<int > a,t;
		for(int j=1;j<=k[i];j++){
			int aa,tt;
			cin>>aa>>tt;
			a.push_back(aa);
			t.push_back(tt);
		}
		for(int i1=0;i1<a.size();i1++){
			for(int i2=i1+1;i2<a.size();i2++){
				f[a[i1]][a[i2]]=min(f[a[i1]][a[i2]],t[i1]+t[i2]);
				f[a[i2]][a[i1]]=min(f[a[i2]][a[i1]],t[i1]+t[i2]);
			}
		}
	}
	cout<<123;
	floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<endl;
	}
}
