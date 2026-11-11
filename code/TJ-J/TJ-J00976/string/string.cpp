#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	char ch;
	long long num;
}a[N];
long long n,x,y,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].ch;
	}
	x=1;
	y=n;
	while(x!=y)
	{
		int k=min(a[x].num,a[y].num);
		if(a[x].ch!=a[y].ch)
		{
			ans+=k;
		}
		a[x].num-=k;
		a[y].num-=k;
		if(a[x].num==0) x++;
		else y--;
	}
	cout<<ans;
	return 0;
} 
