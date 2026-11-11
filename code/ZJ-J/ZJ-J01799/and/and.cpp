#include<bits/stdc++.h>
using namespace std;
long long n,m,v[200005],ans=0,f[5005][5005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		f[i][1]=v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=i;k++)f[i][j]=max(f[i][j],f[i-k][j-1]&v[i]);
		}
	}
	for(int i=1;i<=n;i++)ans=max(ans,f[i][m]);
	cout<<ans;
	return 0;
}