#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N],r[N][4],ans; 

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m,l,cnt; cin >> n >> m;
	r[0][2]=1;
	for(long long i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1); a[0]=a[1];
	
	for(long long i=1;i<=n;i++)
	{
		cnt=r[i-1][3]+(i-r[i-1][2])*(a[i]-a[i-1]);
		for(l=r[i-1][2];l<=i;l++)
		{
			if(cnt<=m) break;			
			cnt-=a[i]-a[l];
		}
		r[i][1]=i-l+1;
		r[i][2]=l;
		r[i][3]=cnt;
		ans=max(ans,r[i][1]);
	}
	cout << ans << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
