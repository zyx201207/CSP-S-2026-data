#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const lint M1=3e5+1000,M2=1e3+100;
lint n;
lint a[M1];
char c[M1];
lint b[M1];
char d[M1];
lint bk,cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(lint i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(lint i=1;i<=n;i++)
	{
		if(c[i]!=c[i-1])
		{
			b[++bk]=a[i];
			d[bk]=c[i];
		}
		else b[bk]+=a[i];
	}
	for(lint i=1,j=bk;i<=j;)
	{
		if(d[i]==d[j])
		{
			if(b[i]>b[j])
			{
				b[i]-=b[j];
				j--;
			}
			else if(b[i]<b[j])
			{
				b[j]-=b[i];
				i++;
			}
			else i++,j--;
		}
		else
		{
			if(b[i]>b[j])
			{
				b[i]-=b[j];
				cnt+=b[j];
				j--;
			}
			else if(b[i]<b[j])
			{
				b[j]-=b[i];
				cnt+=b[i];
				i++;
			}
			else
			{
				cnt+=b[i];
				i++,j--;
			}
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
