#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans,sum;
struct node
{
	long long a;
	char c;
}s[200099];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
		sum+=s[i].a;
	}
	long long yb=sum/2;
	long long u,g;
	for(int i=1;i<=n;i++)
	{
		u+=s[i].a;
//		cout<<u;
		if(u>=yb)
		{
			g=i;
			break;
		}
	}
//	cout<<"g:"<<g<<" "<<yb<<"\n";
	for(int i=1,j=n;i<=g,j>g;i++,j--)
	{
		long long o=s[i].a;
		long long o1=s[j].a;
		if(o==o1&&s[i].c!=s[j].c)
		{
			ans+=o;
//			cout<<ans<<" "<<i<<" "<<j<<"\n";
			continue;
		}
		else if(o==o1&&s[i].c==s[j].c)
		{
			continue;
		}
		else if(s[i].c!=s[j].c&&o1!=o)
		{
			ans+=min(o,o1);
			if(o>o1)
			{
				s[i].a-=min(o,o1);
				i--;
			}
			if(o<o1)
			{
				s[j].a-=min(o,o1);
				j++;
			}
		}
		else if(s[i].c==s[j].c)
		{
			if(o>o1)
			{
				s[i].a-=min(o,o1);
				i--;
			}
			if(o<o1)
			{
				s[j].a-=min(o,o1);
				j++;
			}
		}
	}
	cout<<ans;
	return 0;
}
