#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}b[1]=0;
	long long ans=0;
	if(b[3]*2-b[2]-b[1]>m) cout<<2;
	else{
		for(long long i=3;i<=n;i++){
			b[i]=b[i-1]+b[i]*(i-1);
			if(b[i]<=m) ans=i;
			else break;			
		}		
	}
	cout<<ans;
	return 0;
}