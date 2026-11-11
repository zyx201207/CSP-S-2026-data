#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005]; 
long long c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			b[i]+=a[i]-a[j];
			c[i]+=1;
		}
	}
	for(int i=n;i>=1;i--){
		if(b[i]<=m){
			cout<<c[i];
			break;
		}
	}
	return 0;
} 
