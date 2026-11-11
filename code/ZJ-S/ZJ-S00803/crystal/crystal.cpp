#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500004],b[500004],ans,f;
int main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1])f=1;
	}
	if(f==0){
		long long x=a[2]-a[1];
		for(long long i=1;i<=n;i++){
			b[i]=(a[i-1]+b[i-1])*x;
			if(b[i]>m){
				cout<<b[i-1];
				return 0;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		long long x=0,y=1;
		for(long long j=i-1;j>=1;j--){
			x+=a[i]-a[j];
			if(x<=m)y++;
			else break;
			
		}
		ans=max(ans,y);
	}
	cout<<ans;
	return 0;
}
