#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],maxn;
int oi(int x,int m,int n)
{
	int cnt = 1;
	while(x > 0){
		if(m-(n-a[x]) >= 0){
			m -= (n-a[x]);
			cnt++;
			x--;
		}
		else break;
	}
	return cnt;
 } 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		maxn = max(maxn,oi(i-1,m,a[i]));
	}
	return cout << maxn,0;
}