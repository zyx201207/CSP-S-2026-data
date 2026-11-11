#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int op,t;
	cin>>op>>t;
	while(t--){
		int n,m,a[200005];
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<(a[n]-(m/(a[2]-a[1])+a[2]-a[1]))/(a[2]-a[1])<<'\n';
	}
	return 0;
} 
