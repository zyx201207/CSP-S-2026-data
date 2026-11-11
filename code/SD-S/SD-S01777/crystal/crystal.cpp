#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
long long n,m,a[MAXN],cnt,ans=1,tail,head=1,step=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)
 		cin>>a[i];
 	sort(a+1,a+n+1);
 	for(tail=2;tail<=n;tail++)
	{
		cnt+=(a[tail]-a[tail-1])*step;
		step++;
		while(cnt>m)
		{
			cnt-=(a[tail]-a[head]);
			head++;
			step--;
		}
		ans=max(ans,step);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
