#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[500010];
int sum[300010];
int cnt[3010][5010];
int flag;
int tmp[3010];
bool ck(int x,int y,int st){
	if(a[x]==st)return true;
	for(int i=1;i<=m;i++){
		if(i==st)continue;
		if((cnt[i][y-1]-cnt[i][x-1])&&(cnt[i][n]-cnt[i][y]))return false;
	}
	return true;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[a[i]]++;
		if(a[i]<a[i-1])flag=1;
		tmp[a[i]]=i;
	}
	if(!flag){
		for(int i=1;i<=m;i++){
			sum[i]+=sum[i-1];
			cout<<sum[i]<<" ";
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(j==a[i])cnt[j][i]=cnt[j][i-1]+1;
				else cnt[j][i]=cnt[j][i-1];
			}
		}
		for(int i=1;i<=m;i++){
			int ans=0;
			for(int j=tmp[i];j>=1;j--){
				if(ck(j,tmp[i],i)){
					ans++;
				}
			}
			cout<<ans<<" ";
		}
	}
	return 0;
}
