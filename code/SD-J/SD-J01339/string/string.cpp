#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=1e8+10;
int n;
string s;
ll ans,cha=10000,a[N];
char c[N];
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	int l=0,r=n;
	while(l<=r)
	{
	    if(c[l]!=c[r])
	    {
	    	ans++;
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}
