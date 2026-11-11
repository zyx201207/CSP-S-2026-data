#include<bits/stdc++.h>
using namespace std;
int N=2e5;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int sum=0;
	for(int i=1;i>0;i++){
		sum++;
	}
	long long c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int d,n;
		cin>>n>>d;
		int a[N];
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		for(int k=1;k<=n;k++){
			cout<<a[k]<<" ";
		} 
	}
	return 0;
}