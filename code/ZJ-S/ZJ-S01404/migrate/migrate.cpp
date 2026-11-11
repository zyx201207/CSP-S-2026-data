#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL c,t,n,d,a[2000006],ll[2000005],rr[2000006],ans1,zx,ans;
bool skb=false;
LL find_r(LL k){
	LL l=k,r=n,ans2=n;
	while (l<=r){
		LL mid=(l+r)>>1;
		if (a[mid]-a[k]<=d) ans2=mid,l=mid+1;
		else r=mid-1;
	}
	return ans2;
}
LL find_l(LL k){
	LL l=1,r=k,ans2=k;
	while (l<=r){
		LL mid=(l+r)>>1;
		if (a[k]-a[mid]<=d) ans2=mid,r=mid-1;
		else l=mid+1;
	}
	return ans2;
}
void dfs(LL now,LL end,LL cnt){
	if (skb==true) return ;
	if (now==end){
		if (zx==0) zx=cnt;
		if (zx==cnt){
			ans++;
		}
		if (ans>2){
			skb=true;
		}
	}
	else{
		for (int i=end;i>=now+1;i--){
			if (a[i]-a[now]<=d){
				dfs(i,end,cnt+1);
				if (skb==true) return ;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		ans1=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>a[i];
		if (n>=20){
		for (int i=1;i<=n;i++) rr[i]=find_r(i),ll[i]=find_l(i);
		for (int i=1;i<=n;i++){
			for (int j=n;j>=1;j--){
				if (ll[j]-rr[i]==-1) ans1++;
				if (rr[i]-ll[j]>1) break;
			}
		}
		cout<<ans1<<"\n";
		continue;}
		for (int i=1;i<=n;i++) rr[i]=find_r(i);
		for (int i=1;i<=n;i++)
		  for (int j=i+1;j<=n;j++){
		  	  skb=false;
		  	  dfs(i,j,0);
		  	  if (ans==2) ans1++;
		  	  ans=0;zx=0;
		  }
		cout<<ans1<<"\n";
	}
	return 0;
}
