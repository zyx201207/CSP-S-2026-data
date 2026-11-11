#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
int a[N];
int ne[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ca=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	ca=a[n]-a[n-1];
	int mid=ceil(n/2);
	int ba=1;
	int ans=0;
	while(m-ba*ca>=0)
	{
		m-=ba*ca;
		ans++;
		ba++;
		
	}
	cout<<ans+1<<endl;
	return 0;
}
