#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans,n,t,w;
char c[200005];
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	t=1;
	w=n;
	while(t<=w)
	{
		if(c[t]==c[w])
		{
			if(a[t]<a[w])
			{
				a[w]-=a[t];
				a[t]=0;
				t++;
			}
			else if(a[t]>a[w])
			{
				a[t]-=a[w];
				a[w]=0;
				w--;
			}
			else
			{
				a[t]=0;
				a[w]=0;
				w--;
				t++;
			}
		}
		else
		{
			if(a[t]<a[w])
			{
				cnt+=a[t];
				a[w]-=a[t];
				a[t]=0;
				t++;
			}
			else if(a[t]>a[w])
			{
				cnt==a[w];
				a[t]-=a[w];
				a[w]=0;
				w--;
			}
			else
			{
				cnt+=a[t];
				a[t]=0;
				a[w]=0;
				w--;
				t++;
			}
		}
	}
	cout<<cnt;
	return 0;
}