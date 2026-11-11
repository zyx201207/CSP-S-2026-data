#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	int a[n+2]={0};bool ok=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>3&&a[i]-a[i-1]!=a[i-2]-a[i-3]){
			ok=0;
		}
	}
	if(ok){
		int all=0;
		int s=a[2]-a[1];
		for(int i=1;i<=n;i++){
			all+=i*s;
			if(all>m){
				cout<<i;
				return 0;
			}
		}
	}
	int aa[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			aa[i][j]=a[i]-a[j];
		}
	}
	int axk=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int sum=aa[i][j];
			int k=j+1;
			while(sum<=m&&k!=i){
				sum+=aa[i][k];
				k++;
			}
			if(sum<=m){
				axk=max(axk,k-j);
			}
		}
	}
	cout<<axk+1;
	return 0;
}