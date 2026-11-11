#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long x[500010];
long long y[500010];
long long s[500010];
long long ans=INT_MIN;
void sd(int d,int f){
	if(y[f]+a[f]-a[d-1]<=m&&d>=2){
		y[f]+=a[f]-a[d-1];
		s[f]++;
		sd(d-1,f);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		s[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+n,a+n+1);
	for(int i=2;i<=n;i++){
		x[i]=a[i]-a[i-1];
	}
	s[1]=1;
	for(int i=2;i<=n;i++){
		sd(i,i);
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,s[i]);
	}
	cout<<ans;
	return 0;
}