#include<bits/stdc++.h>//1
using namespace std;
typedef long long ll;

const int N=1e6+16;

int n;
ll m;
ll a[N];

ll ans;

bool check(int x)
{
	if(x>n) return 0;
	
	ll mm=0;
	for(int i=1;i<=x-1;i++)
	{
		if(a[x]-a[i]>=0) mm+=(a[x]-a[i]);
		else break;
	}
	return mm<=m;
}

void ef()
{
	int l=1,r=n+16;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(!check(mid))//m不够 
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
			ans=mid;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

//	freopen("crystal4.in","r",stdin);//

	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	ef();
	
/*
	for(int i=1;i<=n;i++)
	{
		if(check(i))
		{
			ans=i;
		}
		else break;
	}//////////////////////////////
*/

	cout<<ans;
	
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7



快写 

*/