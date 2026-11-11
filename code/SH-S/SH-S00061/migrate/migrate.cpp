#include<bits/stdc++.h>
#define lglg long long
using namespace std;

int cid,T,n;
lglg D,a[2000005],ans;
int nxt[2000005],lst[2000005],rem1[2000005],rem2[2000005],amt1[2000005],amt2[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>cid>>T;
	while(T--){
		cin>>n>>D;for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1,j=1;i<=n;i++){
			while(a[i]-a[j]>D)j++;
			lst[i]=j;
		}
		for(int i=n,j=n;i>=1;i--){
			while(a[j]-a[i]>D)j--;
			nxt[i]=j;
		}
		for(int i=1;i<=n;i++)amt1[i]=amt2[i]=rem1[i]=rem2[i]=0;
		for(int i=1;i<=n;i++){
			if(nxt[i]>i){amt1[nxt[i]]++;rem1[nxt[i]]++;}
			if(lst[i]<i){amt2[lst[i]]++;rem2[lst[i]]++;}
		}
		for(int i=1;i<=n;i++)if(nxt[i]>i&&lst[nxt[i]]==i)amt1[nxt[i]]+=amt1[i];
		for(int i=n;i>=1;i--)if(lst[i]<i&&nxt[lst[i]]==i)amt2[lst[i]]+=amt2[i];
		for(int i=1;i<n;i++)if(nxt[i]>i+1||lst[i+1]<i){
			int v1=(lst[i+1]<i+1&&nxt[lst[i+1]]==i+1&&lst[i]==lst[i+1]?amt1[lst[i+1]]:0)+rem1[i+1]-(nxt[i]==i+1);
			int v2=(nxt[i]>i&&lst[nxt[i]]==i&&nxt[i]==nxt[i+1]?amt2[nxt[i]]:0)+rem2[i]-(lst[i+1]==i);
			ans+=(lglg)v1*v2;
		}
		cout<<ans<<'\n';ans=0;
	}
	return 0;
}
