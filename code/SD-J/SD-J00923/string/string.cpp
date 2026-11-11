#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define cfs cout<<fixed<<setprecision
#define ull unsigned long long
//#define i128 __int128
#define ll long long
#define endl '\n'
using namespace std;
ll a[224524];
char b[224524];
ll ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	IO;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
	}
	int k=n;
	for(int i=1;i<k;)
	{
		if(a[i]<=a[k])
		{
			a[k]-=a[i];
			if(b[i]!=b[k])
			{
				ans+=a[i];
			}
			a[i]=0;
			i++;
		}
		else
		{
			a[i]-=a[k];
			if(b[i]!=b[k])
			{
				ans+=a[k];
			}
			a[k]=0;
			k--;
		}
	}
	cout << ans;
	return 0;
}

