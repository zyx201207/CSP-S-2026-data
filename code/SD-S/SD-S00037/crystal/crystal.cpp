#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],s[N],ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	long long l=1,r=1;
	while(r<=n){
		if(a[r+1]*(r-l+2)-(s[r+1]-s[l-1])<=m){
			r++;
			ans=max(ans,r-l+1);
		}
		else l++;
	}
	cout<<ans;
	return 0;
} 
//I love CCF
