#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=2e6+5;
ll ID,T,n,m,a[MAXN],ans,nxt[MAXN],lst[MAXN],book[MAXN],len[MAXN],len2[MAXN],siz[MAXN],siz2[MAXN],sum,w,dp[MAXN],g[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>ID>>T;
	while(T--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i],len[i]=len2[i]=book[i]=0,siz[i]=siz2[i]=0;
		if(11<=ID&&ID<=12){
			for(int i=1;i<=1;i++){
				dp[i]=0;
				g[i]=1;
				sum=1;
				for(int j=i+1,k=i,z=i;j<=n;j++){
					if(a[j]-a[j-1]>m)break;
					while(a[j]-a[k]>m){
						sum-=g[k];
						k++;
					}
					if(z<k){
						sum=g[k];
						z=k;
					}
					while(z+1<j&&dp[z+1]==dp[k]){
						z++;
						sum+=g[z];
					}
					dp[j]=dp[k]+1;
					g[j]=min(sum,3ll);
					if(g[j]==2)ans+=n-j+1;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		if(13<=ID&&ID<=14){
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=m&&a[n]-a[i]<=m){
					w=i;
					break;
				}
			}
			for(int i=1,j=w;i<w;i++){
				while(j<n&&a[j+1]-a[i]<=m)j++;
				nxt[i]=j;
			}
			for(int i=1;i<w;i++){
				if(nxt[i]>w+1)break;
				if(nxt[i]==w){
					if(i<w-1)ans+=nxt[w-1]-max(w,nxt[w-2]);
				}else ans+=n-max(w+1,nxt[w-1]);
			}
			cout<<ans<<'\n';
			continue;
		}
		if(1<=ID&&ID<=10){
			for(int i=1;i<=n;i++){
				dp[i]=0;
				g[i]=1;
				sum=1;
				for(int j=i+1,k=i,z=i;j<=n;j++){
					if(a[j]-a[j-1]>m)break;
					while(a[j]-a[k]>m){
						sum-=g[k];
						k++;
					}
					if(z<k){
						sum=g[k];
						z=k;
					}
					while(z+1<j&&dp[z+1]==dp[k]){
						z++;
						sum+=g[z];
					}
					dp[j]=dp[k]+1;
					g[j]=min(sum,3ll);
					if(g[j]==2)ans++;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1,j=1;i<=n;i++){
			while(j<n&&a[j+1]-a[i]<=m)j++;
			nxt[i]=j;
			siz[j]++;
		}
		for(int i=n,j=n;i>=1;i--){
			while(j>1&&a[i]-a[j-1]<=m)j--;
			lst[i]=j;
			siz2[j]++;
		}
		for(int i=1;i<=n;i++){
			if(book[i])continue;
			ll x=0,j=i,jj=nxt[i];
			book[i]=i;
			while(nxt[j]>j&&lst[nxt[j]]==j){
				book[nxt[j]]=i;
				len[nxt[j]]=++x;
				j=nxt[j];
			}
			ll jjj=lst[j];
			j=i;
			bool flag=0;
			if(i<=jjj)len2[i]=x+siz2[jjj]-1;
			if(i==jjj)flag=1;
			while(nxt[j]>j&&lst[nxt[j]]==j){
				len2[nxt[j]]=x-len[nxt[j]];
				if(!flag)len2[nxt[j]]+=siz2[jjj]-1;
				if(nxt[j]==jjj)flag=1;
				len[nxt[j]]+=siz[jj]-1;
				j=nxt[j];
			}
		}
		for(int i=2;i<=n;i++)if(book[i]!=book[i-1])ans+=len[i]*len2[i-1];
		cout<<ans<<'\n';
	}
	return 0;
}