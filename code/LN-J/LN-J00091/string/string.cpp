#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
const int M=1e9+10;
int sum;
string a[N];
int num[N];
string t[N];
int n;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i]>>a[i];
		sum+=num[i];
	}
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=num[i];j++)
		{
			t[cnt]=a[i];
			cnt++;
		}
	}
	int mid=sum/2+sum%2;
	int l=1,r=sum+1-l;
	int ans=0;
	while(l<mid)
	{
		l++;
		if(t[l]!=t[r]) ans++;
	}
	cout<<ans;
}
