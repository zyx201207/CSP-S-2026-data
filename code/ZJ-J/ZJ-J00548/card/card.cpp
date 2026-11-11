#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],cnt[M];
vector<int> v;
set<int> s;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	int n,m;
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
	 }
	 if(m==1)
	 {
	 	cout<<n;
	 	return 0;
	 }
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[n])
		{
			cnt[a[i]]++;
		}
		else
		{
			cnt[1]++;
			cnt[2]++;
		}
	}
	cout<<cnt[1]<<" "<<cnt[2];
    return 0;
}
