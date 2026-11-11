#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,aver,sum,total;
long long a[N];
long long pre[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sum+=m;
	long long aver=round(sum*1.0/n);
	sort(a+1,a+n+1);
	int k=1;
	while(a[k]<=aver) k++;
	k--;
	for(int i=1;i<=k;i++)
		total+=abs(a[i]-a[k]);
	int q=1;
	while(total>m)
	{
		total-=abs(a[q]-aver);
		q++;
	}
	cout<<k+1-q;
	return 0;
} 
