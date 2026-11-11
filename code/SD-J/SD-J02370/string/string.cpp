#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
	long long a;
	char b;
}s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	long long sum=0;
	int l=1,r=n;
	while(l<r)
	{
		if(s[l].a<s[r].a)
		{
			if(s[l].b==s[r].b)
			{
				s[r].a-=s[l].a;
				l++;
			}else{
				sum+=s[l].a;
				s[r].a-=s[l].a;
				l++;
			}	
		}else if(s[l].a>s[r].a)
		{
			if(s[l].b==s[r].b)
			{
				s[l].a-=s[r].a;
				r--;
			}else{
				sum+=s[r].a;
				s[l].a-=s[r].a;
				r--;
			}	
		}else{
			if(s[l].b==s[r].b)
			{
				l++;
				r--;
			}else{
				sum+=s[r].a;
				l++;
				r--;
			}	
		}
	}
	cout<<sum;
	return 0;
}
