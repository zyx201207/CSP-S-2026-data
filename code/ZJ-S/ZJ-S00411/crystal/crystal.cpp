#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+100;

int n,m;
int a[N];

void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
}

void solve()
{
	int l=1,used_m=0,cans=0;
	
	for(int i=1;i<=n;i++)
	{
		used_m+=(a[i]-a[i-1])*(i-l);
		
		while(used_m>m && l<i){
			l++;
			used_m-=(a[i]-a[l]);
		}
		
		cans=max(cans,i-l+1);
		
		//cout<<"l=="<<l<<" r=="<<i<<"\n";
	}
	
	cout<<cans;
}

signed main()
{
	freopen("crystal.in" ,"r",stdin );
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	init();
	solve();
	
	return 0;
}
