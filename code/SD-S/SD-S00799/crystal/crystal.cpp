#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e5 + 5;

signed main(){
	freopen("crystal.in ","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m ;
	cin >> n >> m ;
	int a[n+5] ;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] ;
	}
	int s=1 ;
	sort(a+1,a+1+n) ;
	for(int i=2;i<=n;i++)
	{
		int t=0 ;
		for(int j=1;j<=i;j++)
		{
			t+=a[i]-a[j] ;
		}
		if(m>=t)
		{
			s=i ;
		}
	}
	cout << s << endl ;
	return 0;
}
