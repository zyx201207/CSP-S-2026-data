#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=5e5+10;
LL a[MAXN];
int cnt[MAXN];
int main()
{
	freopen("crystal1.in","r",stdin);
	freopen("crystal1.out","w",stdout);
	int n;
	LL m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[i]=1;
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		if(i<ans) break;
		LL temp=m;
		for(int j=i-1;j>=1;j--)
		{
			temp-=a[i]-a[j];
			if(temp<0) break;
			cnt[i]++;
		}
		ans=max(ans,cnt[i]);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
