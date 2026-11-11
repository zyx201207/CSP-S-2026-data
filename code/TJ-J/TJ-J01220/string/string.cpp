#include<bits/stdc++.h>
using namespace std;
long long b[200005]={0};
long long d[200005]={0};
long long f[200005]={0};
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,cnt=0,j=1;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a>>c;
    	for(j=1;j<=a;j++)
    	{
    		b[j+cnt]=c-'a';
		}
		cnt+=a;
	}
	for(int i=1;i<=n;i++)
	{
		d[i]=b[i];
	}
	int cnt2=0;
	for(int i=1;i<=200005;i++)
	{
		f[i]=d[i-cnt2];
		cnt2++;
	}
	int cnt1=0;
	for(int i=1;i<=cnt-1;i++)
	{
		if((f[i]-b[i])!=0)
		{
			cnt1++;
		}
	}
	cout<<cnt1;
    return 0;
}
