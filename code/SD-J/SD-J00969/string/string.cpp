#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;


int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n;
	scanf("%d",&n);
	char c[N],s[N];
	int a[N]={0};
	int len=0;//字符串的总长
	for (int i=1;i<=n;i++)
	{
		scanf("%d%c",&a[i],&c[i]);
		len+=a[i];
		for (int j=(a[i-1]+1);j<=len;j++)//暴力制作字符串 
		{
			s[j]=c[i];
		}
	}
	int ans=0;
	for (int i=1;i<=len;i++)
	{
		if (s[i]!=s[len+1-i])
		{
			ans++;
		}
	}
	cout<<ans/2<<endl;
	return 0;
}

