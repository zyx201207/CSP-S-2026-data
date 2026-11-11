#include<bits/stdc++.h>
using namespace std;
const int maxn=20005;
int m,n;
int a[maxn],f[maxn][maxn];
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[1][1]=a[1];
	for(int i=2;i<=n;i++)f[i][1]=max(f[i-1][1],a[i]);
	for(int j=2;j<=m;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=max(f[i-1][j-1]&a[i],f[i-1][j]);
	cout<<f[n][m]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
