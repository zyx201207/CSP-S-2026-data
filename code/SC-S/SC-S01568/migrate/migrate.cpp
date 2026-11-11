#include<bits/stdc++.h>
using namespace std;

const int maxn=1e4;
int n,d;
int x[maxn];
int dp[maxn][maxn];
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int yy=0;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		int u=x[2]-x[1];
		int h=d/u;
		if(h<2){
			cout<<0<<endl;
			continue;
		}else{
			for(int i=1;i<=n;++i){
				dp[i][i]=1;
			}
			
			for(int i=1;i<=n;++i){
				for(int j=i+3;j<=n;++j){
					if( j-i>=3 ){
						yy++;
					}
					
				}
			}
		}
		cout<<yy<<endl;
	}
	return 0;
}