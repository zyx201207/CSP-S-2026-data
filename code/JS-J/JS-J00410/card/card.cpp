#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1),d(n+1),f(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(d[i]==d[j]){
				for(int k=j;k<=i;k++)d[k]=0;
				for(int i=1;i<=n;i++)f[i]++;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
	cout<<f[i];
	}
	return 0;
}
