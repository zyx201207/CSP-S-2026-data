#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n;
long long a[N],m,c[N],AB[N];
bool _AB=1;
void solvesomeeasy()
{
	sort(a+1,a+1+n);
	int q=0;
	for(int i=1;i<=n;i++)
	{
		int l=i-1,r=i+1,ans=0;
		long long p=m;
		while(p>0&&l>0&&r<=n)
		{
			if(r>n||2*a[i]<a[r]+a[l])
			{
				if(a[i]-a[l]>p)
					p=0;
				else ans++,p-=a[i]-a[l],l--;
			}
			else 
			{
				if(a[r]-a[i]>p)
					p=0;
				else ans++,p-=a[r]-a[i],r++;
			}
//			cout<<1;
		}
		while(p>0&&l>0) 
			if(a[i]-a[l]>p)p=0;
			else ans++,p-=a[i]-a[l],l--;
		while(p>0&&r<=n) 
			if(a[r]-a[i]>p)p=0;
			else ans++,p-=a[r]-a[i],r++;
		if(ans>0) ans++;
		q=max(q,ans);
//		cout<<1;
	}
	cout<<q;
	return ;
}
void solveAB()
{
	long long q=0,g=AB[n];
	for(int i=2;i<=n;i++)
	{
		q+=g*i;
		if(q>m)
		{
			cout<<i-1;
			return ;
		}
	}
	cout<<n;
	return ;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		AB[i]=a[i]-a[i-1];
		if(AB[i]!=AB[i-1]&&i>1)
			_AB=0;
//		MAX=max(MAX,abs(a[i]));
	}
	if(_AB==1)
		solveAB();
	else 
		solvesomeeasy();
	return 0;
}