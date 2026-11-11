#include<bits/stdc++.h>
using namespace std;
int c,t,d1,flag[100][100][100],j[100],x[100],minn=1<<30;
inline void dfs(int cnt,int i,int j,int d,int sum){
	if(sum == d && cnt == j){
		j[++flag[i][j][d]]=d;
		return;
	}
	for(int k=cnt+1;k<=j&&k-cnt<=d1;k++){
		dfs(cnt,i,j,d,sum+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n;
		cin >> n >> d1;
		for(int i=1;i<=n;i++) cin >> x[i];
		for(int d=1;d<n;d++){
			for(int i=1;i<=n-d;i++){
				for(int j=1;i+j<=n;j++){
					dfs(i,i,j,d,1);
					for(int l=1;l<=flag[i][j][d];l++){
						minn = min(minn,j[l]);
					}
				}
			}
		}
		
	}
}
