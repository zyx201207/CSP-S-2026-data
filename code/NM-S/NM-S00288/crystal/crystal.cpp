#include<bits/stdc++.h>
using namespace std;
bool cmp(long a,long b){
	return a>b;
}
long long ans[500020],w[500020],a[500020],ma=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,m1=0,n1=0;
	scanf("%lld%lld", &n, &m);
	for(int i=0;i<n;i++)scanf("%lld", &a[i]);
	sort(a,a+n);
	a[n]=0xffffff;
	ans[0]=1;
	for(int i=0;i<n;i++){
		w[i]=a[i+1]-a[i];
		if(m1+(ans[n1]*w[i])<=m){
			m1=m1+(ans[n1]*w[i]);
			ans[n1]++;
		}
		else if(m1+(ans[n1]*w[i])-a[i]+a[i-ans[n1]]<m){
			m1=m1+(ans[n1]*w[i])-a[i]+a[i-ans[n1]];
		}
		else {
			n1++;
			m1=0;
			ans[n1]++;
		}
	}
	m1=0;n1--;int e=n-1;
	sort(ans,ans+n1,cmp);
	for(int i=n-2;i>=0;i--){
		if(m1+(a[e]-a[i])<=m){
			m1=m1+(a[e]-a[i]);
			ma++;
		}
		else if(m1+(a[e]-a[i])-((a[e]-a[e-1])*(ma-1))<m){
			m1=m1+(a[e]-a[i])-((a[e]-a[e-1])*(ma-1));
			e--;
		}
		else {
			ans[0]=max(ans[0],ma);
			m1=0;
			ma=1;
		}
	}

	cout<<ans[0];
	return 0;
} 

