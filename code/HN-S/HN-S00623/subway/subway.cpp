#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int N2=5e5+5;
int c,n,m,d,q,k;
int a,x,y;
int ans;
int w[N],f[N],t[N][N];
//vector<vector<int>> r1(N2);
//vector<vector<int>> r2(N2);
void dfs(int x){
	
}
//bool check(int x,int r){
//	int l=0;r=n+1;
//	while(l<=r){
//		int mid=(l+r)>>1;
//  		if(r1[r+1][mid]<x)
//  	}
//}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a;
			//r1[i].push_back(a);
			cin>>t[i][a];
		}
	}
//	for(int i=1;i<=n-1;i++){
//		for(auto j:r1[i]){
//			if(check(j,i)){
//				
//			}
//		}
//	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		
		cout<<ans+w[x]+w[y];
	}
	return 0;
}
