#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
const int N=2e5+10;
ll a[N],f[N][N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(f,0,sizeof f);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	f[1][0]=0;
	f[1][1]=a[1];
	for (int i=2;i<=n;i++){
		f[i][i]=f[i-1][i-1]&a[i];
		f[i][0]=0;
		f[i][1]=a[1];
	}
	
	for (int i=2;i<=n;i++){
		for (int j=2;j<=m;j++){
			f[i][j]=max(f[i-1][j],f[i][j-1]&a[i]);
		}
	}
	cout<<f[n][m];
	return 0;
}
