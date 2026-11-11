#include<bits/stdc++.h>
using namespace std;
int n;
long long a[400010];
char c[400010];
long long sum=0,ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long sun=sum/2;
	for(long long i=0;i<sun;i++){
		if(s[i]!=s[sum-i-1])
		  ans++;
	}
	cout<<ans;
	return 0;
} 
