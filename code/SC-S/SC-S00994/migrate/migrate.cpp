#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000005]; 
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=(n+5);i++){
			a[i]=0;
		}
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int len=a[n]-a[1];
		cout<<len+1-d<<"\n";		
	}
	return 0;
}            