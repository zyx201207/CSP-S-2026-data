#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500010];
struct node{
	int id,t;
};
node z[500010];
int a[500010][500010];//floyd
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m+1;i++){
		for(int j=1;j<=m+1;j++){
			a[i][j]=INT_MAX/2;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int e;
		cin>>e;
		for(int j=1;j<=e;j++){
			cin>>z[i].id>>z[i].t;
		}
		for(int j=2;j<=e;j++){
			for(int k=1;k<j;k++){
				a[z[k].id][z[j].id]=min(a[z[k].id][z[j].id],z[k].t+z[j].t);
				a[z[j].id][z[k].id]=min(a[z[j].id][z[k].id],z[k].t+z[j].t);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				a[i][j]=min(a[i][j],a[i][k]+a[j][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int start,end;
		cin>>start>>end;
		cout<<a[start][end];
	}
	return 0;
}
