#include <bits/stdc++.h>
using namespace std;

const int N=20020000;
long long n,m,a[N],ans,num,b[N],w,ll,q;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	w=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==i)
		{
			ll++;
			m-=i;
			if(m>=0)
			{
				ans++;
				q=1;
			}
		}
		else
		{
			q=0;
		}
	}
	if(q==1)
	{
		cout<<ans+1<<" ";
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		ans=1;
		m=w;
		for(int j=1;j<=n;j++)
		{
			b[j]=a[j];
		}
		for(int w=i-1;w>=1;w--)
		{
			while(b[w]<b[i])
			{
				if(m==0)
				{
					break;
				}
				b[w]++;
				m--;
			}
			if(b[w]==b[i])
			{
				ans++;
			}
		}
		if(ans<=num)
		{
			break;
		}
		num=max(ans,num);
	}
	cout<<num;
	return 0; 
}
