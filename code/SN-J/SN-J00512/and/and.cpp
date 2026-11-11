#include <bits/stdc++.h>
using namespace std;

int n,m,a[200005],pow2[35];
int a_,len,maxl,ans,cnt,sum;
bool B[200005][35],f[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		a_ = a[i],len = 0;
		while(a_ > 0)
		{
			len++;
			B[i][len] = (a_ % 2);
			a_ >>= 1;
		}
		maxl = max(maxl,len);
	}
	pow2[0] = 1;
	for(int i=1;i<=30;i++)pow2[i] = pow2[i-1]*2;
	for(int i=maxl;i>=1;i--)
	{
		sum = 0;
		for(int j=1;j<=n;j++)
		{
			if(f[j]==0 && cnt!=0)continue;
			if(B[j][i] == 1)sum++,f[j] = 1;
		}
		if(sum >= m)
		{
			cnt++;
			ans += pow2[i-1];
			for(int j=1;j<=n;j++)
				if(B[j][i] == 0)
					f[j] = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
