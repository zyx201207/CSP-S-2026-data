#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	const long long N=1e6+10;
	int n;
	long long m;
	long long a[N];
	int num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1, a+1+n);
	long long k[N][N];
	long long c[N][N];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			k[i][j-1]=a[i];
			k[i][j]=k[i][j-1]+a[j];
			c[i][j]=(j-i)*a[j]-k[i][j-1];
			if(c[i][j]>m){
				num=max(num, j-i);
				break;
			}
			if(c[i][j]<=m){
				num=max(num, j-i+1);
			}
		}
	}
	cout<<num;
	return 0;
}