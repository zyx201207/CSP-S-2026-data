#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int cnt=0,l=1,maxx=-1;
	for(int i=2;i<=n;i++)
	{
		//cerr << a[i] << " ";
		int ew=(a[i]-a[i-1])*(i-l);
		cnt+=ew;
		if(cnt>m)
		{
			maxx=max(maxx,i-l);
			while(cnt>m)
			{
				//cerr << l << " ";
				cnt-=(a[i]-a[l]);
				//cout << cnt << ";" << m << " ";
				l++;
			}
			//cerr << i << ";" << l << " ";
		}
	}
	cout << max(maxx,n-l+1);
	return 0;
}
