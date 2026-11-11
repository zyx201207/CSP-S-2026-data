#include<bits/stdc++.h>
using namespace std;
long long n,h;
struct node
{
	long long num;
	char ch;
}x[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n;
	for(int i=0;i<n;i++)cin>>x[i].num>>x[i].ch;
	int l=0,r=n-1;
	long long sum;
	while(l<r)
	{
		if(x[l].num==x[r].num)
		{
			sum=x[l].num;
			h+=sum*(x[l].ch!=x[r].ch);
			l++,r--;
		}
		else if(x[l].num<x[r].num)
		{
			sum=x[l].num;
			x[r].num-=sum;
			h+=sum*(x[l].ch!=x[r].ch);
			l++;
		}
		else
		{
			sum=x[r].num;
			x[l].num-=sum;
			h+=sum*(x[l].ch!=x[r].ch);
			r--;
		}
		
	}
	cout<<h;
	return 0;
}
