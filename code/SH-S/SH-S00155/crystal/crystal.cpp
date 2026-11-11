#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[1000010],r;
map<long long,unsigned long long> b;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		unsigned long long k;
		cin>>k;
		if(!b.count(k))
		{
			a[r++]=k;
		}
		b[k]++;
	}
	sort(a,a+r);
//	for(int i=0;i<r;i++)
//		cout<<b[a[i]]<<" ";
//	cout<<endl;
	unsigned long long ans=b[a[0]],p1=1,cnt=0,pc=0,c=0;
	for(unsigned long long i=1;i<r;i++)
	{
		cnt+=b[a[i-1]];
		c+=(a[i]-a[i-1])*cnt;
		//cout<<i<<"-------"<<endl;
		//cout<<c<<" "<<cnt<<" "<<ans<<"--"<<cnt+b[a[i]]<<endl;
		if(c<=m)
		{
			ans=max(ans,cnt+b[a[i]]);
			//cout<<"p"<<endl;
			continue;
		}
		while(c>m&&p1<=i)
		{
			c-=(a[i]-a[p1-1])*pc;
			//cout<<"pc-"<<pc<<" c-"<<c<<" p1-"<<p1<<" i-"<<i<<endl;
			cnt-=pc;
			p1++;
			pc=b[a[p1-1]];
		}
		if(m-c<0)
		{
			p1=i;
			c=0;
		}
		p1=min(p1,i);
		pc=min((m-c)/(a[i]-a[p1-1]),b[a[p1-1]]);
		pc=max(pc,(unsigned long long)0);
		c+=pc*(a[i]-a[p1-1]);
		cnt+=pc;
		//cout<<"c-"<<c<<" pc-"<<pc<<" p1-"<<p1<<" cnt-"<<cnt<<endl; 
		ans=max(ans,cnt+b[a[i]]);
	}
	cout<<ans;
} 
