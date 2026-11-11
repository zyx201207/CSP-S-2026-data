#include<bits/stdc++.h>
using namespace std;
long long a[200100],n,m;
int f[15000][15000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) f[i][0]=a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			f[i][j]=max(f[i-1][j-1]&a[i],(long long)f[i-1][j]);
	cout<<f[n][m-1];
}
