#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],vis[5010],lsum[5010],eras[5010];
bool reach[5010],sum[5010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n>5000){
		ll sum[200010];
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			sum[a[i]]++;
		}
		sum[a[n]]=n;
		for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
		return 0;
	}
    for(int i=1;i<=n;i++){
		memset(vis,-1,sizeof(vis));
		memset(reach,true,sizeof(reach));
		memset(sum,true,sizeof(sum));
		memset(eras,0,sizeof(eras)); 
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=-1&&eras[a[j]]>0) for(int k=vis[a[j]];k<j;k++){
				if(!reach[k]) continue;
				reach[k]=false;
				eras[a[k]]--;
				if(eras[a[k]]==0) vis[a[k]]=-1;
			}
			vis[a[j]]=j;
			eras[a[j]]++;
		}
		for(int j=i;j<=n;j++){
			if(reach[j]&&sum[a[j]]) lsum[a[j]]++,sum[a[j]]=false;
		}
	}
	lsum[a[n]]=n;
	for(int i=1;i<=m;i++) cout<<lsum[i]<<' ';
	return 0;
}
