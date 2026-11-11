#include<bits/stdc++.h>
using namespace std;
const int M = 5e5+5;
long long a[M],cf[M],pre[M];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	long long n,m,x;
	scanf("%lld %lld",&n,&m);
	a[0] = 0;pre[0] = 0;cf[0] = 0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		a[i] = x;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		cf[i] = a[i+1] - a[i];
		pre[i] = pre[i-1]+cf[i];
	}
	long long l=1,r=1,c=0,ans=1,len=1;
	while(r<n){
		r++;
		len = r-l+1;
		c+=(len-1)*cf[r-1];
		if(c<=m){
			ans = len;
		}
		else if(c>m){
			c = c-(pre[r-1]-pre[l-1]);
			l++;
		}
	}
	cout << ans;	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


