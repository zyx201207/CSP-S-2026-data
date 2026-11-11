#include<bits/stdc++.h> 
using namespace std;
long long n,m,cnt,maxn;
const int N=5e5+50;
long long a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=2,size=2,cnt=a[r]-a[l];
	while(r<=n)
	{
		if(cnt>m)
		{
			cnt=cnt-(a[r]-a[l]);
			l++;
			size--;
		}
		else
		{
			r++;
			if(r>m) break;
			cnt=cnt+(a[r]-a[r-1])*size;
			if(maxn<size) maxn=size;
			size++;
		}
	}
	cout<<maxn;
}
