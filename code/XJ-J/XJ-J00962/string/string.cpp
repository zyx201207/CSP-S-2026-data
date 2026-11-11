#include<bits/stdc++.h>
using namespace std;
string s;
char a[200005];
long long n,m,k,t=0,b[200005],len,ans;
int fun(int x)
{
	int f,h;
	int flag=1;
	for(f=1,h=len;f<=sqrt(len),h>=f;f++,h--)
	{
		if(s[f]!=s[h])
		{
			flag=0;
			ans++;
		}
	}
	return flag;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>b[i]>>a[i];
		len+=b[i];
	}
	for(i=1;i<=n;i++)
	{
		k=b[i];
		while(k--)
		{
			t++;
			s[t]=a[i];
		}
	}
	if(fun(1)==1)
	{
		cout<<ans;
		return 0;
	}
	cout<<ans;
	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/
