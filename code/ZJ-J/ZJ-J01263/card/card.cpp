#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],b[5010],l,ans[300010],c[5010];
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]<a[i-1]){
			return 0;
		}
	}
	return 1;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(check()){
		for(int i=1;i<=n;i++) ans[a[i]]++,ans[a[n]+1]--;
		for(int i=1;i<=m;i++) ans[i]+=ans[i-1];
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		l=0;
		memset(c,0,sizeof c);
		for(int j=i;j<=n;j++){
			int t=0,tt=0;
			for(int k=1;k<=l;k++){
				if(b[k]==a[j]){
					t=1,tt=k;
					break;
				}
			}
			if(t) l=tt-1;
			b[++l]=a[j];
		}
		for(int j=1;j<=l;j++) c[b[j]]=1;
		for(int j=1;j<=m;j++) ans[j]+=c[j];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
