#include<bits/stdc++.h>
using namespace std;
const int op=5e5+5;
long long a[op];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n,m;cin>>n>>m;
	double aa=0;
	bool flagA=1,flagB=1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=(i+1))flagA=0;
		if(i>1 && a[i]-a[i-1]!=a[i-1]-a[i-2])flagB=0;
		aa+=a[i];
	}//O(n)
	//cout<<flagB<<endl;return 0;
	if(flagA)//考虑特性A 
	{
		for(int i=1;i<n;i++)
		{
			if((i*(i+1)/2)>m)
			{
				cout<<i;
				fclose(stdin);fclose(stdout);
				return 0;
			}
		}
	}
	if(flagB)//考虑特性B 
	{
		sort(a,a+n);
		long long d=a[2]-a[1];//公差 
		for(int i=0;i<n;i++)
		{
			if(i*(i+1)*d/2>m)
			{
				cout<<i;
				fclose(stdin);fclose(stdout);
				return 0;
			}
		}
	}
	if((!flagA) && (!flagB)){
	aa+=m;
	double aaa=0.0;
	aaa=aa/n;
	double aaaa=1000000000.0;
	long long aaaaa=0;
	for(int i=0;i<n;i++)
	{
		if(aaaa>abs(a[i]-aaa))
		{
			aaaaa=a[i];
		}
		aaaa=min(aaaa,abs(a[i]-aaa));
	}//O(n)
	sort(a,a+n);
	long long aaaaaa=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==aaaaa)
		{
			aaaaaa=i;break;
		}
	}
	long long aaaaaaaa=aaaaaa;
	aaaaaa--;
	long long ans=0;
	for(;aaaaaa>=0;aaaaaa--)
	{
		long long aaaaaaa=aaaaa-a[aaaaaa];
		if(m>=aaaaaaa)
		{
			ans++;
			m-=aaaaaaa;
		}
		else
		{
			break;
		}
	}
	for(int i=aaaaaaaa;i<n;i++)
	{
		if(a[i]==aaaaa)ans++;
		else break;
	}cout<<ans;}//伪证
	fclose(stdin);
	fclose(stdout);
	return 0;
}
