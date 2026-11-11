#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100000005];
char c[100000005];
string zh;
long long len=0,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++){
			zh+=c[i];
		}
		len+=a[i];
	}
	for(int i=0;i<len/2;i++){
		if(zh[i]!=zh[len-i-1]) ans++;
	}	
	cout<<ans;
	return 0;
}
