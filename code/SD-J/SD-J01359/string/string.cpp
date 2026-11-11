#include<bits/stdc++.h>
using namespace std;
long long n,ans,cnt;
long long a[200005],p[200005];
char c[200005];
struct abc
{
	long long s;
	char a;
};
vector<abc>l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		ans+=a[i];
	}
	long long mid=ans/2;
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]+a[i];
		if(ans%2==1)
		{
			if(p[i-1]<mid&&mid+1<p[i])
			{
				r.push_back(abc{p[i]-mid-1,c[i]});
				l.push_back(abc{mid-p[i-1],c[i]});
				continue;
			}
			if(p[i]<=mid)
			{
				l.push_back(abc{a[i],c[i]});
				continue;
			}
			if(mid+1<p[i])
			{
				r.push_back(abc{min(p[i]-mid-1,a[i]),c[i]});
			}
			
		}
		if(ans%2==0)
		{
			if(p[i-1]<mid&&mid<p[i])
			{
				r.push_back(abc{p[i]-mid,c[i]});
				l.push_back(abc{mid-p[i-1],c[i]});
				continue;
			}
			if(p[i]<=mid)
			{
				l.push_back(abc{a[i],c[i]});
				continue;
			}
			if(mid<p[i]);
			{
				r.push_back(abc{a[i],c[i]});
			}
		}
	}
	for(int i=0,j=0;i<l.size()||j<r.size();i++,j++)
	{
		if(l[i].s<r[j].s&&l[i].a!=r[j].a)
		{
			cnt+=l[i].s;
			r[j].s-=l[i].s;
			j-=1;
			continue;
		}
		if(l[i].s>r[j].s&&l[i].a!=r[j].a)
		{
			cnt+=r[j].s;
			l[i].s-=r[j].s;
			i-=1;
			continue;
		}
		if(l[i].s==r[j].s&&l[i].a!=r[j].a)
		{
			cnt+=l[i].s;
			continue;
		}
	
	}
	cout<<cnt<<endl;
	return 0;
	
}
