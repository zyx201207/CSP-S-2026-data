#include<bits/stdc++.h>
using namespace std;
long long f[2005][2005];//前n个选了m个的最大按位与 
long long n,m;
long long a[200005];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n>20){
		cout<<a[m];
		return 0;
	}
	for(int i=1;i<=n;i++){
		f[i][1]=max(f[i-1][1],a[i]);
		for(int j=2;j<=m;j++){
			f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
		}
	}
	cout<<f[n][m];
	return 0;
}
