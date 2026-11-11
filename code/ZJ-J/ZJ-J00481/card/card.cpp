#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],sum[N],lst[N],f[N],h;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],sum[a[i]]++;
	for(int i=n;i;i--)if(lst[a[i]]==0)lst[a[i]]=i,h=i,f[i]=1;
	for(int i=h;i<n;i++)if(f[i])sum[a[i+1]]+=sum[a[i]];
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}
