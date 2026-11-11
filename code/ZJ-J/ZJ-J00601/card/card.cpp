#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,s,ans,la,a[500010],dis[500010],l[500010],
f[500010],d[500010],p[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)d[i]=2e9;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=2;i<=n;i++)
		if(a[i-1]<=a[i])s++;
	if(s==n-1){
		for(i=1;i<=n+1;i++)
			if(a[i]!=a[i-1])ans+=i-1;
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(i=1;i<=n;i++){
		if(l[a[i]]) 
			for(j=l[a[i]]+1;j<=i-1;j++)
				if(d[j]>j-l[a[i]]){
					d[j]=j-l[a[i]];
					p[j]=l[a[i]];
				}
		l[a[i]]=i;
	}
	for(i=n;i>=1;i--)
		if(!f[a[i]])
			if(d[i]==2e9)dis[a[i]]=i,f[a[i]]=1;
			else{
				la=i;
				for(j=i-1;j>=1;j--)
					if(a[j]==a[i]){
						if(d[j]==2e9)dis[a[i]]+=j;
						else
							if(p[j]!=p[la])dis[a[i]]+=d[j];
						la=j;
					}
				dis[a[i]]+=d[i];
				f[a[i]]=1;
			}
	for(i=1;i<=m;i++)cout<<dis[i]<<" ";
}