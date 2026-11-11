#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],cha[500010],c,t,tot,i,j,k,l,r;
int main()
{
	freopen("crystal.in","/r",stdin);
	freopen("crystal.out","/w",stdout);
	cin>>n>>m>>a[0];
	for(i=1;i<n;++i)
	{
		cin>>a[i];
		cout<<"i="<<i<<"  a[i]="<<a[i]<<"  cha[i-1]="<<cha[i-1]<<endl;
	}
	sort(a,a+n);
	for(i=1;i<n;++i)
	{
		cha[i-1]=a[i]-a[i-1];
		cout<<"a[i]="<<a[i]<<"  cha[i-1]="<<cha[i-1]<<endl;
	}
	for(i=1;i<n;++i)
	{
		int t1=t;
		++r;
		for(j=0;j<i;++j)
		{
			t1+=cha[j];
		}
		if(t1<=m)
		{
			t=t1; 
		}
		else
		{
			break;
		}
	}
	for(j=i+1;j<n;++j)
	{
		if(cha[j]==0 or cha[j])
		{
			++r;
			++tot;
		}
	}
	tot=r-l;
//	cout<<"tot="<<tot<<" l="<<l<<" r="<<r<<endl;
	m-=t;
	for(i=r;i<n;++i)
	{
		if(cha[i-1]*tot<=a[i]-a[l])
		{
			m=m-a[i]+a[l]+cha[r]*tot;
			++l;
			++r;
			for(j=i+1;j<n;++j)
			{
				if(cha[j]*tot<=m)
				{
					m-=cha[j]*tot;
					++tot;
				}
			}
		}
//		cout<<"tot="<<tot<<" l="<<l<<" r="<<r<<endl;
	}
	for(i=l;i<r;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<tot;
	return 0;
} 
