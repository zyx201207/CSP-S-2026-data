#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
long long a[N],pre[N],n,m,id,ans;
void find(int l,int r,long long p)
{
	if(l>r) return ;
	long long mid=(l+r)/2;
	if((p-mid+1)*a[p]-(pre[p]-pre[mid-1])<=m)
	{
		id=min(id,mid);
		find(l,mid-1,p);
	}else find(mid+1,r,p);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(long long i=1;i<=n;i++)
	{
		id=1e9;
		find(1,i,i);
		ans=max(i-id+1,ans);
	}
	cout<<ans;
	return 0;
}