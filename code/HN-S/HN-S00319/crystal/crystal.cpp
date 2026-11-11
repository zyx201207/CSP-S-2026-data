#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,jg,aa;
long long a[500005];
int main(){  
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	
	for(long long i=1,j=1;i<n && j<n;){
		j++; if(j>n) j=n;
		ans+=(j-i)*(a[j]-a[j-1]);
		if(ans<=m)
			jg=max(jg,j-i+1);	
		else 
			i++,ans-=(a[j]-a[i]);
		
	} 
	cout<<jg;
	return 0;
} 
