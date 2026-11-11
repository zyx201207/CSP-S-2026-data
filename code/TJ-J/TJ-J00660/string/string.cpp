#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
struct word
{
	int a;
	char b;
}w[N];
struct zm
{
	int add;
}z[27];

int sum,s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<"0";
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>w[i].a>>w[i].b;
			s+=w[i].a;
			if(i>1)
			{
				if(w[i].b==w[i-1].b)
				{
					w[i].a+=w[i-1].a;
				}
				else{
					sum++;
				}
			}
			if(i==n&&sum==1)
			{
				if(w[i].a<=w[i-1].a) 
				{
					cout<<w[i].a;
					return 0;
				}else{
					cout<<w[i-1].a;
					return 0;
				}
			}
		}
	
		
	}
	if(sum==0) 
	{
		cout<<"0";
		return 0;
	}
	if(s%2==0)
	{
		cout<<s/2;
	}
	else{
		cout<<s/2-1;
	}
	return 0;
}

