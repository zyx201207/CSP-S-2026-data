#include <bits/stdc++.h>
using namespace std;
int sum=-10000;
int mw=-10000;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long f[1000005];
	long long fx[1000005][10000005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		
	}
	for(int i=1;i<=n;i++){
		fx[1][i]=f[i];
		fx[i][1]=f[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			fx[i][j]=max(fx[i][j-1],(f[i]&f[j]));
		}
	}
	cout<<sum;
}
