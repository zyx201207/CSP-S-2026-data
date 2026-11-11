#include<bits/stdc++.h>
#define int long long
using namespace std;
const int cxk=5e5+5;
int n,m,a[cxk],s[cxk],ans=0;
bool check(int x,int i)
{
	int sum=s[i]-s[x-1];
	return a[i]*(i-x+1)-sum<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		int lt=0,rt=i+1,mid;
		while(lt+1<rt)
		{
			mid=(lt+rt)/2;
			if(check(mid,i))//[mid,i]¿É·ñ 
				rt=mid;
			else
				lt=mid;
		}
		//cout<<i-rt+1<<"\n";
		ans=max(ans,i-rt+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
