#include<iostream>
#define MAXN 200005
using namespace std;
int l,r;
long long ans;
struct node
{
	int a;
	char c;
}str[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;i++)
		cin>>str[i].a>>str[i].c;
	while(l<r)
	{
		long long cnt=0;
		if(str[l].c==str[r].c)
		{
			if(str[l].a==str[r].a)
				l++,r--;
			else if(str[l].a<str[r].a)
			{
				cnt+=str[l].a;
				str[r].a-=str[l].a;
				l++;
			}
			else
			{
				cnt+=str[r].a;
				str[l].a-=str[r].a;
				r--;
			}
		}
		else
		{
			ans+=cnt;
			cnt=0;
			if(str[l].a<str[r].a)
			{
				ans+=str[l].a;
				str[r].a-=str[l].a;
				l++;
			}
			else
			{
				ans+=str[r].a;
				str[l].a-=str[r].a;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
