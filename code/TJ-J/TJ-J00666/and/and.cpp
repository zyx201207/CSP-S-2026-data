#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100001]={0},maxa=0,cnt=0,c=0,e=0,d[1001],ans=0;
string l;
struct node
{
	string v;
	int p;
}b[100001];
int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
		maxa=max(maxa,a[i]);
	}
	if (m==1)
	{
		cout << maxa;
		return 0;
	}
	/*if (m==2)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if ((a[i]&a[j])>cnt)
					cnt=(a[i]&a[j]);
			}
		}
		cout << cnt;
		return 0;
	}*/
	while (1)
	{
		if (pow(2,c)>=maxa)
			break;
		c++;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=c;j>=0;j--)
		{
			if(a[i]-pow(2,j)>=0)
			{
				b[i].v+="1";
				a[i]-=pow(2,j);
			}
			else
				b[i].v+="0";
		}
		b[i].p=1;
	}
	for (int i=1;i<=c+1;i++)
	{
		for (int j=0;j<n;j++)
		{
			l=b[j].v;
			if (l[i-1]=='1' && b[j].p==1)
				e++;
			else
			{
				if (i==1 && e==0)
					b[j].p=1;
				else
					b[j].p=0;
			}
		}
		if (e>=m)
			d[i]=1;
		else
			d[i]=0;
		e=0;
	}
	for (int i=1;i<=c+1;i++)
		ans+=d[i]*pow(2,c-i+1);
		cout << ans;
	return 0;
}
