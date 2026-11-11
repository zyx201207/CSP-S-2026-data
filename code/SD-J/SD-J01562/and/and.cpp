#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int N=2e5+10;
int a[N];
int m;
int mask;
int check(int idx)
{
	int nw=mask|(1<<idx);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if((nw|a[i])==a[i]) cnt++;
	}
	return cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=30;i>=0;i--)
	{
		if(check(i)>=m)
		{
			mask|=(1<<i);
		}
	}
	cout<<mask;
	return 0;
 } 
