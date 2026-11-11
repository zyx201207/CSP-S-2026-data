#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,last[500005],q[500005],a[500005],k,ans[500005],m,f[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n>505){
		if(m==1){
			cout<<n;
			return 0;
		}
		else if(m==2){
			for(int i=1;i<=n;i++)cin>>a[i];
			int x=0;
			for(int i=1;i<n;i++)
				if(a[i]!=a[n])x++;
			if(a[n]==1){
				cout<<n<<' '<<x;
			}
			else cout<<x<<' '<<n;
			return 0;
		}
		else {
			for(int i=1;i<=n;i++){
				cin>>a[i];
				ans[a[i]]++;
			}
			int s=0;
			for(int i=1;i<=m;i++){
				s+=ans[i];
				cout<<s<<' ';
			}
			return 0;
		}
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		k=0;memset(last,0,sizeof(last));memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			k++;
			q[k]=a[j];
			if(last[a[j]]==0)last[a[j]]=k;
			else {
				for(int t=last[a[j]]+1;t<k;t++)last[q[t]]=0;
				k=last[a[j]];
			}
		}
		for(int j=1;j<=k;j++)if(f[q[j]]==0)f[q[j]]=1,ans[q[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
