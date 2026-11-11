#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
int ans[500005],cnt[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int f=1;
	for(int i=2;i<=n;i++){
		if(a[i-1]>a[i]){
			f=0;
			break;
		}
	}
	if(f&&(n*m+n*n>50000000)){
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			if(cnt[i])ans[i]++;
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				ans[a[i]]+=i-1;
			}
		}
		for(int i=1;i<=n;i++){
			cnt[a[i]]--;
			if(cnt[a[i]]>0)ans[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(!cnt[a[i]])cnt[a[i]]=i;
			else{
				for(int j=cnt[a[i]];j<=i;j++){
					cnt[a[j]]=0;
				}
				cnt[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			if(cnt[i])ans[i]++;
			cnt[i]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

