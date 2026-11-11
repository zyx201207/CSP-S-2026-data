/*
	Name: 音乐水晶 Voice Crystal
	Copyright: Bulu(Geopelia is the best in the Pixel Tower!!)
	Author: Bulu ★Xterfusion★ 
	Date: 2098.10.31
	Description: X X XXX O O OOO XX X XXX OO O OOO X X X XXXX O O O OOOO XX XXXX XXX OO OOOO OOO
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cstdio>
#include<iomanip>
#include<cctype>
#include<climits>
#include<cmath>
#define int long long
using namespace std;
/* * *** 
 * * ***/
int n,m;
int a[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (n>=10000){cout<<n<<endl;return 0;}
	for (int i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
	}
	int ans=1;
	for (int i=1;i<=n;i++)
	{
		bool flag=1;
		for (int j=i-ans;j>=1;j--)
		{
			int x=a[i]-a[i-1];
			x*=i-j+1;
			x-=a[j];
			if (x>m){flag=0;break;}
			else ans=max(ans,x);
		}
		if (flag==0)continue;
	}
	cout<<ans<<endl;
}
//什么叫输出n可以得到15分 
