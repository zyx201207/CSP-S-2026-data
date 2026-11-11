#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	const long long N=1e7+10;
	int c, t, n;
	long long d;
	long long x[N];
	cin>>c>>t;
	int cnt[N];
	for(int i=1;i<=t;t++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int k=1;k<=n-2;k++){
			for(int l=k+2;l<=n;l++){
				int len=x[l]-x[k];
				if(len>d && len<2*d) cnt[i]++;
			}
		}
	}
	for(int i=1;i<=t;i++) cout<<cnt[i]<<endl;
	return 0;
}