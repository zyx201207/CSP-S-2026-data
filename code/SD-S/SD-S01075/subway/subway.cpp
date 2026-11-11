#include<iostream>
#include<vector>
using namespace std;
const int N=5e5+20;
vector<int> v[N];
int c,n,m,d,q,w[N],k[N],a[505][N],t[505][N],minn=0x3f3f3f,l,r;
void dfs(int l,int r,int shijian){
	if(l==r){
		minn=min(minn,shijian);
	}
	for (int i=1;i<=v[l].size();i++){
		if(v[l][i]>l){
			dfs(v[l][i],r,shijian+=t[l][v[l][i]]);
		}
	}
}
int main(){
	freopen("subway,in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for (int j=1;j<=2*k[i];j++){
			for (int k1=1;k1<=2*k[i];k1++){
				if(a[i-1][j]==a[i][k1]){
					for (int y=1;y<=2*k[i];y++){
						v[i].push_back(a[i][y]);
					}
				}
			}
		}
	}
	for (int i=1;i<=q;i++){
		cin>>l>>r;
		dfs(l,r,0);
		cout<<minn;
	}
	return 0;
}
