#include<bits/stdc++.h>
using namespace std;
string a;
long long n,x,cnt=1,ans;
char y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>x;
		cin>>y;
		for(int i=cnt;i<=cnt+x;i++) a[i]=y;
		cnt+=x;
	}
	for(int i=1;i<=cnt/2;i++)
	{
		if(a[i]!=a[cnt+1-i]) ans++;
	}
	cout<<ans;
	return 0;
}