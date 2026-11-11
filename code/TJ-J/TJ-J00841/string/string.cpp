#include<bits/stdc++.h>
using namespace std;
string a;
long long n,x,ans,b[200];
char y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>x>>y;
		 while(x)
		 {
		 	a+=y;
		 	x--;
		 }
	}
	long long len=a.size();
	for(long long i=0;i<len;i++)
	{
		long long j=len-1-i;
		if(j<=i)break;
		if(a[i]==a[j])continue;
		ans++;
	}
	cout<<ans;
	return 0; 
}	
