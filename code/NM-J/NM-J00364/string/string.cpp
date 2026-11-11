#include<bits/stdc++.h>
using namespace std;
long long n,a,ans,tmp,b1;
char c,b[1000000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++) b[++b1]=c;
	}
	for(long long i=1;i<=b1/2;i++)
	{
		if(b[i]!=b[b1-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}

