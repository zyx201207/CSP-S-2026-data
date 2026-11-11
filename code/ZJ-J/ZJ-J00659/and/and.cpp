#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,x,c[200010],a[200010][40],b[200010],cnt,s,
ans=2147483647,j;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>c[i];x=c[i];
		for(j=31;j>=1;j--) a[i][j]=x%2,x/=2;	
	}
	for(j=1;j<=31;j++){
		cnt=0;s=0;
		for(i=1;i<=n;i++)
			if(b[i]==0&&a[i][j]==1) cnt++;
		if(cnt<m) continue;
		for(i=1;i<=n;i++)
			if(b[i]==0&&a[i][j]==0) b[i]=1;
		for(i=1;i<=n;i++) if(b[i]==0) s++;
		if(s==m){
			for(i=1;i<=n;i++)
				if(b[i]==0) ans&=c[i];
			cout<<ans;return 0;
		}
	}
	sort(c+1,c+1+n);
	for(i=1;i<=n;i++) if(b[i]==0) ans&=c[i];
	cout<<ans;
	return 0;
}