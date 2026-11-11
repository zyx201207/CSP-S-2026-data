#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n;
int sum;
struct node
{
	int a;
	char c;
}s[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a;
		cin>>s[i].c;
	}
	for(int i=1,j=n;i<=n,j>=1;)
	{
		if(s[i].c!=s[j].c)
		{
			int l=min(s[i].a,s[j].a);
			sum+=l;
			s[i].a-=l;
			s[j].a-=l;
			if(s[i].a==0) i++;
			if(s[j].a==0) j--;		
		}
		else 
		{
			int l=min(s[i].a,s[j].a);
			s[i].a-=l;
			s[j].a-=l;
			if(s[i].a==0) i++;
			if(s[j].a==0) j--;			
		}
			if(i>=j) 
				break;
	}
	cout<<sum<<endl;
	return 0;
}
