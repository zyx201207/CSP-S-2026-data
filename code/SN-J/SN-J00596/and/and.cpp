#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],cnt[35],w[35],tot,b[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;(1ll<<j)<=a[i];j++){
			if(a[i]&(1ll<<j)) cnt[j]++;
		}
	}
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m) w[++tot]=i;
	}
	for(int i=1;i<=tot;i++){
		int k=0;
		for(int j=1;j<=n;j++){
			if(a[j]&(1ll<<w[i])) b[++k]=a[j];
		}
		if(k<m) continue;
		ans+=(1ll<<w[i]);
		for(int j=1;j<=k;j++) a[j]=b[j];
		n=k;
	}
	cout<<ans;
	return 0;
}
