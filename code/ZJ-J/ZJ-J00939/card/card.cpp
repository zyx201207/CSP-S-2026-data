#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
const int mo=1e9+7;
ll mod(ll x){
	return (x%mo+mo)%mo;
}
const int N=5e5+5,M=3e5+5;
int n,m,a[N],b[N],ans[M],id[M];
bool vis[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++) id[j]=0;
		for(int j=i;j<=n;j++){
			if(!id[a[j]]) b[++cnt]=a[j],id[a[j]]=cnt;
			else{
				for(int k=id[a[j]]+1;k<=cnt;k++)
					id[b[k]]=0;
				cnt=id[a[j]];
			} 
		}
		for(int j=1;j<=cnt;j++)
			ans[b[j]]++;
	}	
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}

