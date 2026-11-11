#include<bits/stdc++.h>
using namespace std;
void init(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
const int N=5e5+9;
long long n,m,a[N];
int main(){
	init();
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=1;
	for(long long i=2;i<=n;i++){
		long long l=1,sum=0;
		for(l=1;sum<m;l++){
			if(i-l<1)break;
			sum+=abs(a[i]-a[i-l]);
		}
		if(sum==m)ans=max(ans,l);
		else ans=max(ans,l-1);
	}
	cout<<ans;
	return 0;
}
