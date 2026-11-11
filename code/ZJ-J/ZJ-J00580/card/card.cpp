#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,n,m,fl[500010],a[500010],sum[500010],q[500010],f[500010];
void jg(int x){
	int i;
	f[x]++;
	for(i=x;i<=n;i++)
		if(q[a[i]]!=i){
			f[i]--;	
			jg(q[a[i]]);break;
		}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=n;i>=1;i--){
		if(fl[a[i]]==1)jg(q[a[i]]);
		else {
			fl[a[i]]=1;q[a[i]]=i;jg(q[a[i]]);
		}	
	}
	for(i=1;i<=n;i++)f[i]+=f[i-1];
	for(i=n;i>=1;i--)
		if(sum[a[i]]==0)sum[a[i]]=f[i];
	for(i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}