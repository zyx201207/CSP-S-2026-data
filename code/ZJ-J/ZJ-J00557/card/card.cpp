#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int n,m,a[N],b[M],s[M],ans[M];
void baoli(int t){
	int res=0,cnt=0;
	for (int i=1;i<=m;i++) b[i]=s[i]=0;
	for (int i=t;i<=n;i++)
	{
		if (b[a[i]]==0) s[++cnt]=a[i],b[a[i]]=cnt;
		else
		{
			while (cnt>b[a[i]]) b[s[cnt]]=0,cnt--;
		}
	}
	for (int i=1;i<=cnt;i++) ans[s[i]]++;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (m==1)
	{
		cout<<n;
		return 0;
	}
	if (m==2)
	{
		int sum1=0,sum2=0;
		for (int i=1;i<=n;i++)
			if (a[i]==1) sum1++;
			else sum2++;
		if (a[n]==1) cout<<n<<" "<<sum2;
		else cout<<sum1<<" "<<n;
		return 0;
	}
	for (int i=1;i<=n;i++) baoli(i);
	for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}