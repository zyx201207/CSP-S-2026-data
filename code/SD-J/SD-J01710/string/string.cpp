#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long n;
long long a[3*N];
char c[3*N];
long long s[3*N];
long long ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		scanf("%d %c",a+i,c+i);
		s[i]=s[i-1]+a[i];
	}
	long long l=1,r=s[n];char lc=c[1],rc=c[n];long long i=1,j=n;
	while(l<r&&i<j){
		if(s[i]-l+1>r-s[j-1]){
			if(lc!=rc)ans+=r-s[j-1];
			l+=r-s[j-1];
			r=s[j-1];
			rc=c[--j];
		}
		if(s[i]-l+1<r-s[j-1]){
			if(lc!=rc)ans+=s[i]-l+1;
			r-=s[i]-l+1;
			l=s[i]+1;
			lc=c[++i];
		}
		if(s[i]-l+1==r-s[j-1]){
			if(lc!=rc)ans+=r-s[j-1];
			l=s[i]+1;
			r=s[j-1];
			lc=c[++i];
			rc=c[--j];
		}
	}
	cout<<ans;
	return 0;
}

