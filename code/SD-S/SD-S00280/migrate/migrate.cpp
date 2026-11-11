#include<bits/stdc++.h>
using namespace std;
__int128 f[309][309],f1[309][309],f2[309][309];
void solve(){
	int n,d;
	cin>>n>>d;
	vector<long long>x(n+1);
	for(int i=1;i<=n;i++){;
		cin>>x[i];
		for(int j=1;j<i;j++){
		f[j][i]=1000000000000000000;
		f[j][i]*=300;
		f1[j][i]=0;
		f2[j][i]=f[j][i];
		if(x[i]-x[j]<=d){
			f[j][i]=1;
			f2[j][i]=1;
		}
	}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<=j;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<j;k++){
				if(f2[i][k]+f2[k][j]==f[i][j]){
					f1[i][j]++;
				}
				f2[i][j]=min(f2[i][j],f2[i][k]+f2[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f1[i][j]==2){
			//	cout<<i<<" "<<j<<"\n";
			ans++;	
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
} 
