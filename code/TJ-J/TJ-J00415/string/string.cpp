#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long a;
	char c;
} a[200010];
node l[200010],r[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long m=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].c;
		m+=a[i].a;
		
	}

	long long cnt=0;
	int ol=0,orr=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt+a[i].a<=m/2)
		{
			l[++ol].a=a[i].a;
			l[ol].c=a[i].c;
			cnt+=a[i].a;
		}
		else
		{
			l[++ol].a=m/2-cnt;
			l[ol].c=a[i].c;
			break;
		}
	}
	cnt=0;
	for(int i=n;i>=1;i--)
	{
		if(cnt+a[i].a<=m/2)
		{
			r[++orr].a=a[i].a;
			r[orr].c=a[i].c;
			cnt+=a[i].a;
		}
		else
		{
			r[++orr].a=m/2-cnt;
			r[orr].c=a[i].c;
			break;
		}
	}
	if(l[ol].a==0) ol--;
	if(r[orr].a==0) orr--;
	long long yu=0; //l left
	char qwe;
	long long j=1,ans=0;
	for(int i=1;i<=ol;i++)
	{
		yu=l[ol].a;
		qwe=l[ol].c;
		for(;j<=orr;j++)
		{
			if(yu>=r[j].a)
			{
				if(qwe!=r[j].c) ans+=r[j].a;
				yu-=r[j].a;
			}
			else{
				if(qwe!=r[j].c) ans+=yu;
				r[j].a-=yu;
				break;
			}
		}
		//cout<<ans<<' ';
	}
	//cout<<endl;
	//for(int i=1;i<=ol;i++)
	//{
	//	cout<<l[i].a<<' '<<l[i].c;
	//}
	//cout<<endl;
	//for(int i=1;i<=orr;i++)
	//{
	//	cout<<r[i].a<<' '<<r[i].c;
	//}
	
	cout<<ans;
	return 0;
} 
