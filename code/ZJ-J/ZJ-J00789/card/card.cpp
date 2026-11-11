#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mx=5e5+5;
int n,m,a[mx],b[mx],mp[mx],ans[mx],c[mx];
void solve(){
	for(int i=1;i<=n;i++)b[i]=a[n-i+1];
	for(int i=1;i<=n;i++){
		if(!mp[b[i]])mp[b[i]]=i;
		else{
			for(int j=mp[b[i]]+1;j<i;j++){
				ans[b[j]]+=i-j,mp[b[j]]=0,b[j]=0;
			}
			b[i]=0;
		}
	}
	for(int i=1;i<=n;i++)ans[b[i]]+=(n-i+1);
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";	
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],c[i]=a[i];
	if(n*m>650000000){
		solve();
		return 0;
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(!mp[a[i]]&&a[i]>0)mp[a[i]]=i;
			else{
				int kk=mp[a[i]];
				for(int k=mp[a[i]];k<i;k++){
					if(a[i]<0)k=-a[k];
					mp[a[k]]=0,a[k]=0;
				}
				a[kk]=-i;
				mp[a[i]]=i;
			}
		}
		for(int i=j;i<=n;i++)
			if(a[i]>0)b[a[i]]=1;
			else a[i]=c[i];
		for(int i=1;i<=m;i++)ans[i]+=b[i],b[i]=0,mp[i]=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
