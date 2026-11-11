#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[200001];
int mp[200001][200001];
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					mp[i][j]++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(mp[i][j]==2){
					ans++;
				}
			}
		}
		n--;
		cout<<n;
		return 0;
		cout<<ans;
	}
	return 0;
} 
