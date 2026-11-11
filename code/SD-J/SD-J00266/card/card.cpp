#include<bits/stdc++.h>
using namespace std;
long long a[500002],ans[300001];
int l[5001][3001];
bool f[5001][3001];
int ll[200001][3];
bool ff[200001][3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000||m<=2){
		if(m<=2){
			for(int i=n;i>=1;i--){
				if(ll[i+1][a[i]]==0){
					for(int j=1;j<=m;j++){
						ans[j]+=ff[i+1][j];
						ff[i][j]=ff[i+1][j];
						ll[i][j]=ll[i+1][j];
					}
					ans[a[i]]++;
					ff[i][a[i]]=1;
					ll[i][a[i]]=i;
				}
				else{
					ll[i][a[i]]=ll[i+1][a[i]];
					for(int j=1;j<=m;j++){
						ans[j]+=ff[ll[i+1][a[i]]][j];
						ff[i][j]=ff[ll[i+1][a[i]]][j];
						ll[i][j]=ll[i+1][j];
					}
				}
			}
			for(int i=1;i<=m;i++){
				cout<<ans[i]<<' ';
			}
		}	
		else{
			for(int i=n;i>=1;i--){
				if(l[i+1][a[i]]==0){
					for(int j=1;j<=m;j++){
						ans[j]+=f[i+1][j];
						f[i][j]=f[i+1][j];
						l[i][j]=l[i+1][j];
					}
					ans[a[i]]++;
					f[i][a[i]]++;
					l[i][a[i]]=i;
				}
				else{
					l[i][a[i]]=l[i+1][a[i]];
					for(int j=1;j<=m;j++){
						ans[j]+=f[l[i+1][a[i]]][j];
						f[i][j]=f[l[i+1][a[i]]][j];
						l[i][j]=l[i+1][j];
					}
				}
			}
			for(int i=1;i<=m;i++){
				cout<<ans[i]<<' ';
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				ans[a[i]]+=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
