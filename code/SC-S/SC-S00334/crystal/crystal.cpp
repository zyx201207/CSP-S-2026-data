#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[10005],b[10005],mj,j;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long x=abs(a[i]);
		for(int j=1;j<=n;j++){
			cin>>b[j];
			b[j]=x-a[i];
		}
	} 
	max(mj,b[j]);
	cout<<b[j]; 
	return 0;
}
