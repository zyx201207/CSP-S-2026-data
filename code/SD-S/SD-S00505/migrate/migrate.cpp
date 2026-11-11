#include<bits/stdc++.h>
using namespace std;
int f[909][909],f1[909][909],f2[909][909];
vector<int>a[909]; 
void solve(){
	int n,q;
	cin>>n>>d;
	vector<int>x(n+1);
	for(int i=1;i<=n;i++){
		a[i].clean();
		cin>>x[i];
		for(int j=1;j<i;j++){
			f[j][i]=998244353;
			f1[j][i]=0;
			f2[j][i]=f[j][i];
			if(x[i]-x[j]<=d){
				a[i].push_back({j,x[i]-x[j]});
				f[j][i]=x[i]-x[j];
			}
		}
	}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;i++){
				for(int k=i+1;k<=j;k++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j])
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;i++){
				for(int k=i+1;k<=j;k++){
					if(f2[i][k]+f2[k][j]==f[i][j]){
						f1[i][j]++;
					}
					f2[i][j]=min(f2[i][j],f1[i][k]+f2[k][j]);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(f1[i][j]==2){
					
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
