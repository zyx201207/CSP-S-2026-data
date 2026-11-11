#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long n[100000],d[100000],c,t,a[100][10000];
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		cin>>n[j]>>d[j];
		for(int i=1;i<=n[j];i++){
			cin>>a[j][i];
		}
	}
	for(int i=1;i<=t;i++){
		int sum=0;
		for(int j=1;j<=n[i];j++){
			sum+=a[i][j];
		}
		if(sum-5<=0)cout<<0<<'\n';
		else{
			cout<<(sum-5)/5<<'\n';
		}
	} 
	return 0;
}
 
