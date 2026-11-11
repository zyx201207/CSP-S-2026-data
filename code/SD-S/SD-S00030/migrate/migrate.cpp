#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,a[1000010];
int bts(int x){
	int l=1,r=x,mid,ans=x;
	while(l<=r){
		mid=(l+r)/2;
		if(a[x]-a[mid]<=d){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int l[1000010],lo[1000010][3];
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
int c,t;
cin>>c>>t;
while(t--){
	memset(lo,0,sizeof lo);
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)l[i]=bts(i);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(l[i]==1){
			lo[i][1]=i-1;
			continue;
		}
		int j=l[i];
		lo[i][1]=lo[l[j]][1]-lo[l[j]+1][1]+(i-l[i])+1;
		for(int j=l[i];j<=i;j++)lo[i][2]+=lo[j][2];
		lo[i][2]+=lo[l[i]+1][1]-lo[l[i]+2][1];
		ans+=lo[i][2];
	}
	cout<<ans<<endl;
}	
	return 0;
}

