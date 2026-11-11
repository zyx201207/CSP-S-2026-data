#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2001],f[2001][2001];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)f[i][1]=a[1];
	for(int i=2;i<=n;i++){
		for(int j=2;j<=min(i,m);j++)f[i][j]=max(f[i][j-1]&a[j],f[i-1][j]);
	}
	cout<<f[n][m];
	return 0;
}
