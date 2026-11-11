#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
struct node{
	int a;
	char c;
}; 
long long ans;
node s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
	}
	int l=1,r=n;
	while(l<r)
	{
		if(l==r)
		{
			break;
		}
		if(s[l].c==s[r].c)
		{
			if(s[l].a==s[r].a)
			{
				l++,r--;
			}
			else if(s[l].a>s[r].a)
			{
				s[l].a-=s[r].a;
				r--;
			}
			else
			{
				s[r].a-=s[l].a;
				l++;
			}
		}
		else
		{
			if(s[l].a==s[r].a)
			{
				ans+=s[l].a;
				l++,r--;
				
			}
			else if(s[l].a>s[r].a)
			{
				s[l].a-=s[r].a;
				ans+=s[r].a;
				r--;
			}
			else
			{
				s[r].a-=s[l].a;
				ans+=s[l].a;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
