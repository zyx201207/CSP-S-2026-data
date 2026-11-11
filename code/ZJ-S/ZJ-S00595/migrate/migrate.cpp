#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int T,n,m,a[N],b[N],c[N],ans,sum;
void baoli(int x){
	for (int i=x;i<=n;i++) b[i]=0,c[i]=2e9;
	b[x]=1;c[x]=0;
	for (int i=x;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (a[j]-a[i]<=m)
			{
				if (c[i]+1<c[j]) c[j]=a[i]+1,b[j]=b[i];
				else if (c[i]+1==c[j]) b[j]+=b[i];
			}
			else break;
	for (int i=x+1;i<=n;i++)
		if (b[i]==2) ans++;
}
void dengchashulie(){
	for (int i=2;i<=n/2;i++)
		if ((a[2]-a[1])*i<=m&&m<(a[2]-a[1])*(i+1))
		{
			cout<<n-i*2+1<<"\n";
			return ;
		}
	cout<<"0\n";
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>T>>T;
	while (T--)
	{
		cin>>n>>m;ans=sum=0;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<n-1;i++)
			if (a[i+1]-a[i]==a[i+2]-a[i+1]) sum++;
		if (sum==n-2) dengchashulie();
		else
		{
			for (int i=1;i<n-1;i++) baoli(i);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
