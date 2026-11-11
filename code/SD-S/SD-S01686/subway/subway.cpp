#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=1e5+5;
int c,n,m,d,q;
int w[M],k[N],a[N][N],t[N][N],ans_h,ans_n,cnt;
void dfs(int x,int y){
	if(x==y){
		if(ans_n<ans_h){
			ans_h=ans_n;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		bool f=0;
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x){
				f=1;
				ans_n+=t[i][j];
				break;
			}
		}
		if(f){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]!=x){
					ans_n+=t[i][j];
					dfs(a[i][j],y);
					ans_n-=t[i][j];
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		ans_h=ans_n=0;
		int x,y;
		cin>>x>>y;
		dfs(x,y);
		cout<<ans_h<<"\n";
	}
	return 0;
}
