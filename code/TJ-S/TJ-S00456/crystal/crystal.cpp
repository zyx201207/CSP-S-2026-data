#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[n+1]=0;
	for(int i=n;i>1;i--){
		b[i]=b[i+1]+(a[i]-a[i-1]);
	}
	c[n+1]=0;
	for(int i=n;i>1;i--){
		c[i]=c[i+1]+b[i];
	}
	
	for(int i=n;i>1;i--){
		if(m<c[i]){
			
			cout<<n-i+1;
			return 0;
		}
	}
}
