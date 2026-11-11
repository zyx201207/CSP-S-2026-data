#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int w[N];
int a[505][2005];
int t[505][2005];
vector<int> edge[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			edge[a[i][j]].push_back(a[i][j-1]);
			edge[a[i][j-1]].push_back(a[i][j]);
		}
		for(int j=1;j<=k;j++){
			for(int h=j+1;h<=k;h++){
				t[a[i][j]][a[i][k]]=t[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(t[x][y]==0){
			cout<<t[x][2]+t[2][y]<<endl;
		}
		else{
			cout<<t[x][y]<<endl;
		}
	}
	return 0;
}