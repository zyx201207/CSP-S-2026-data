#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pjs,jc=1000000000000000000,xs,bh,ans;
bool f=0;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pjs+=a[i];
	}
	sort(a+1,a+n+1);
	pjs/=n;
	for(int i=1;i<=n;i++)
	{
		if(abs(a[i]-pjs)<jc)
		{
			jc=abs(a[i]-pjs);
			bh=i;
			xs=a[i];
		}
		else if(abs(a[i]-pjs)==jc&&bh<i)
		{
			jc=abs(a[i]-pjs);
			bh=i;
			xs=a[i];
		}
	}
	//cout<<xs<<endl;
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	//cout<<endl;
	for(int i=bh;i>=1;i--)
	{
		if(m<0)
		{
			f=1;
			break;
		}
		else if(m==0)break;
		int cz=xs-a[i];
		m-=cz;
		a[i]+=cz;
	}
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=n;i++)if(a[i]==xs)ans++;
	if(f)cout<<ans-1;
	else cout<<ans;
}
