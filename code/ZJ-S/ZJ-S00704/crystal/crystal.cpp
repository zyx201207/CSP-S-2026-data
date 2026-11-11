#include<bits/stdc++.h>
using namespace std;
long long a[514514],b[514514][2],c,l;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	long long fl=a[0],fl1=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=fl)
		{
			b[c][0]=fl;
			b[c++][1]=fl1;
			fl=a[i];
			fl1=1;
		}
		else
		{
			fl1++;
		}
	}
	if(fl1!=0)
	{
		b[c][0]=fl;
		b[c++][1]=fl1;
	}
	long long cost=0,ans=0;
	fl=b[0][0];
	fl1=0;
	for(int i=0;i<c;i++)
	{
		cost+=(b[i][0]-fl)*fl1;
		fl1+=b[i][1];
		while(cost>m&&l<=i)
		{
			long long del=cost-m;
			if(del>(b[l][1])*(b[i][0]-b[l][0]))
			{
				cost-=b[l][1]*(b[i][0]-b[l][0]);
				fl1-=b[l][1];
				l++;
				continue;
			}
			long long del1=del/(b[i][0]-b[l][0]);
			if(del1*(b[i][0]-b[l][0])<del)del1++;
			cost-=del1*(b[i][0]-b[l][0]);
			fl1-=del1;
			b[l][1]-=del1;
		}
		ans=max(ans,fl1);
		fl=b[i][0];
	}
	cout<<ans;
	return 0;
}


