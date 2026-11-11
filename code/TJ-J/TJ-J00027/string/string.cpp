#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node
{
	int a;
	string b;
};
signed main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int n;
	cin>>n;
	vector<Node> node(n+10);
	for (int i=1;i<=n;i++)
	{
		cin>>node[i].a>>node[i].b;
	}
	int l=1,r=n;
	int sum=0;
	while (l<r)
	{
		if (node[l].b==node[r].b)
		{
			if(node[l].a==node[r].a)
			{
				l++;
				r--;
				continue;
			}
			else if (node[l].a<node[r].a)
			{
				//sum+=node[r].a-node[l].a;
				node[r].a-=node[l].a;
				l++;
				continue;
			}
			else
			{
				//sum+=node[l].a-node[r].a;
				node[l].a-=node[r].a;
				r--;
				continue;
			}
		}
		else
		{
			if(node[l].a==node[r].a)
			{
				sum+=node[l].a;
				l++;
				r--;
				continue;
			}
			else if (node[l].a<node[r].a)
			{
				//sum+=node[r].a-node[l].a;
				node[r].a-=node[l].a;
				sum+=node[l].a;
				l++;
				continue;
			}
			else
			{
				//sum+=node[l].a-node[r].a;
				node[l].a-=node[r].a;
				sum+=node[r].a;
				r--;
				continue;
			}
		}
	}
	cout<<sum;
	return 0;
}
