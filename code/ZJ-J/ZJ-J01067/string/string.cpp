#include<bits/stdc++.h>
using namespace std;
struct dt
{
	int long long num;
	char ch;
}a[200010];
int n,m,i,j,k,l;
int long long sum,min1;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i].num>>a[i].ch;
		j=1;k=n;
	while(j<k)
	{
		if(a[j].ch==a[k].ch)
		{
			min1=min(a[j].num,a[k].num);
			a[j].num-=min1;
			a[k].num-=min1;
		}
		if(a[j].ch!=a[k].ch)
		{
			min1=min(a[j].num,a[k].num);
			sum+=min1;
			a[j].num-=min1;
			a[k].num-=min1;
		}
		if(a[j].num==0)
		j++;
		if(a[k].num==0)
		k--;
	}
	cout<<sum;
	return 0;
}
