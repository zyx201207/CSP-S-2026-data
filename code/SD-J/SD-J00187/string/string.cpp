#include <bits/stdc++.h>
using namespace std;
string s;
long long n,a[200010],ans=0,b[200010],lfa=0;
char c[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	b[0]=0;
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=b[i-1]+a[i]; 
		lfa+=a[i]; 
		for(int j=b[i-1]+1;j<=b[i];j++){
			s[j]+=c[i];
		} 
	} 
	long long p=lfa/2;
	for(long long  i=1;i<=p;i++){
		if(s[i]!=s[lfa-i+1]){
			s[lfa-i+1]=s[i];
			ans++;
		}
	} 
	cout<<ans<<endl; 
	return 0;
}
