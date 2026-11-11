#include<bits/stdc++.h>
using namespace std;
struct jiegou
{
	int num;
	char s;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	jiegou a[200001];
	int n;
	long long m=0;
	cin>>n;
	if(n==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].s;
	}
	int t=1,w=n;
	while(t!=w)
	{
		if(a[t].num<a[w].num)
		{
			if(a[t].s!=a[w].s)
			{
				m+=a[t].num;
			}
			a[w].num-=a[t].num;
			t++;
		}
		else
		{
			if(a[t].s!=a[w].s)
			{
				m+=a[w].num;
			}
			a[t].num-=a[w].num;
			w--;
		}
	}
	cout<<m;
	return 0;
} 
