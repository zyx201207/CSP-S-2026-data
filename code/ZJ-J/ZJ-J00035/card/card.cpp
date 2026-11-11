#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int n,m,a[N],p[N],ans[M],sum[N],st[N];
map<int,int>mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int ok=1,ok2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) ok=0;
		if(a[i]>a[i-1]&&i!=1) ok2=0;
		p[i]=1;
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	if(ok){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cout<<i<<" ";
			}
		}
		return 0;
	}
	if(ok2){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]) ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	//	cout<<1;
		return 0;
	}
	int pos=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) mp[j]=0;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==1){
				while(st[pos]!=a[j]){
					mp[st[pos]]=0;
					pos--;
					//cout<<j;
				}
				pos--;
			}
			st[++pos]=a[j];
			mp[a[j]]=1;
		}
		while(pos>0){
			ans[st[pos]]++;
			//if(q.front()==2) cout<<i;
			pos--;
		}
	}
	//cout<<ok;
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
