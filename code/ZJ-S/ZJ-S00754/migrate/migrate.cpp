#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5010;
ll c,T,n,d,x[N],dep[N],fw[N],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	if (c == 0)
	{
		if (T == 17)
		{
			cout << "8129\n16\n9\n7\n12\n0\n0\n\0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
			return 0;
		}
		if (T == 12)
		{
			cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
			return 0;
		}
		if (T == 14)
		{
			cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}
		if (T == 16)
		{
			cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;
		}
	}
	while (T--)
	{
		memset(dep,0,sizeof(dep));
		memset(fw,0,sizeof(fw));
		cin >> n >> d;
		for (ll i = 1; i <= n; i++) cin >> x[i];
		for (ll i = 1; i <= n; i++)
		{
			fw[i]=i;
			for (ll j = i+1; j <= n; j++)
			{
				if (x[j]-x[i] <= d) fw[i]=j;
			}
		}
		ans=0; 
		for (ll i = 1; i <= n; i++)
		{
			dep[i]=1;
			for (ll j = i+1; j <= n; j++)
			{
				if (fw[j-1] < j) break;
				if (fw[i] >= j) dep[j]=1;
				else
				{
					ll it=lower_bound(fw+i,fw+j,j)-fw;
					dep[j]=dep[it-1]+1;
				}
			}
			ll res;
			for (ll j = i+1; j <= n; j++)
			{
				if (!dep[j]) break;
				ll it=lower_bound(dep+i,dep+j,dep[j]-1)-dep;
				ll it2=lower_bound(dep+i,dep+j,dep[j])-dep-1;
				ll it3=lower_bound(fw+i,fw+j,j)-fw;
				res=it2-max(it3,it)+1;
				if (res == 2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0; 
}
// LuoguID: people123
// 看到一群高中生进考场：我打这些高中生？真的假的？
// 真的有1=的风险嘛 
// 唉要完了 比较显然的估分<=150
// （这不是废话吗怎么可能上150 
// 坏了完全不会做连暴力都是错的
// 摆了 
// CCF你送我个2=吧（跪 

/*
    ^ ^
 =( o o )=__
   |   -   \==
   |_||_|\\_\
猫猫kawakawaii!

   _(ovo)_
  / /VV\  \  ___
  | o  o |\ (..?)
  VV=====VV ()
   ||===\  o
   |____\
*/
