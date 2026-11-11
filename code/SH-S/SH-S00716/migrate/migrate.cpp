#include<bits/stdc++.h>
using namespace std;
#define ll long long;
ll c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		int x[2000005]={};
		for(int j=0;j<n;j++){
			int a;
			cin>>a;
			x[j]++;
		}
		cout<<n/2;
	}
	return 0;
} 
