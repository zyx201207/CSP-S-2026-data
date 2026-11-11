#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long s[500005];
ll n,m,a[500005],ans[300005],vis[500005];
ll cnmccf(ll x){
	ll r=0;
	for(int i=x;i<=n;i++){
		if(vis[a[i]]==0){
			r++;
			s[r]=a[i];
			vis[a[i]]=1;
		}
		else{
			while(s[r]!=a[i]){
				vis[s[r]]=0;
				r--;
			}
		}
	}
	while(r){
		ans[s[r]]++;
		r--;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int sb=1;sb<=n;sb++){
		memset(vis,0,sizeof(vis));
		cnmccf(sb);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
