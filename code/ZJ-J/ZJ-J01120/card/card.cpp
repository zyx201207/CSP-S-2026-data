#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],wz[300010],lk[500010];
long long int ans[300010];
void solve(){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum++;
		if(a[i]!=a[i+1]){
			ans[a[i]]=sum;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2){
			if(a[i]<a[i-1])flag=0;
		}
	}
	if(flag){
		solve();
		return 0;
	}
	for(int i=n;i>=1;i--)
		if(wz[a[i]]==0)wz[a[i]]=i;
	for(int i=1;i<=n;i++)lk[i]=wz[a[i]];
	for(int i=1;i<=n;i++){
		ans[a[i]]++;
		int p=lk[i]+1;
		while(p<=n){
			ans[a[p]]++;
			p=lk[p]+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}