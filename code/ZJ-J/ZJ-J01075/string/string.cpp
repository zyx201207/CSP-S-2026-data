#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	string s;
	s+=' ';
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long ans=0;
	for(long long i=1;i<=sum/2;i++){
		if(s[i]!=s[sum+1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
