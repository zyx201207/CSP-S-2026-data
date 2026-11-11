#include <bits/stdc++.h>
using namespace std;
string a;
long long n,ans,jj;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long p;char c;
		cin>>p>>c;
		for(long long j=1;j<=p;j++){
			a+=c;
		}
	}
	jj=a.size()-1;
	for(long long i=0;i<a.size()/2;i++){
		if(a[i]!=a[jj])ans++;
		jj--;
	}
	cout<<ans;
	return 0;
}
