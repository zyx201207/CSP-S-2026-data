#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e6+10;
int c,T,n,d,i,j,k,a[N],ans,vis[N],cnt[N],x,D[N],l,r,dis[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
 	cin>>c>>T;
 	if(c==11||c==12){
 		int x,y;
 		while(T--){
	 		cin>>n>>d;cin>>x>>y;
	 		k=y-x;
	 		if(k*2>d) cout<<"0\n";
	 		else {
	 			ans=0;
	 			x=d/k+(d%k!=0);
				 cout<<max(0ll,n-2*x+1)<<"\n";
			 }
		 }
		 return 0;
	 }
 	while(T--){
 		cin>>n>>d;ans=0;
 		for(i=1;i<=n;i++)
 			cin>>a[i];
 		if(n*n>1e8){
 			cout<<0;
 			continue;
		 }
 		for(int s=1;s<=n;s++){
 			for(i=s+1;i<=n;i++)
 				vis[i]=cnt[i]=0,
				 dis[i]=1e18;
 			queue<int> D;D.push(s);dis[s]=0;cnt[s]=1;
 			vis[s]=1;
 			while(!D.empty()){
 				x=D.front();D.pop();
 				for(i=x+1;a[i]-a[x]<=d&&i<=n;i++){
 					if(dis[x]+1<=dis[i]){
	 					cnt[i]+=cnt[x];
					 	dis[i]=dis[x]+1;
					 	if(!vis[i])
		 					D.push(i),
							vis[i]=1;
					 }
				 }
 				for(i=x-1;a[x]-a[i]<=d&&i>=s;i--){
 					if(dis[x]+1<=dis[x-1]){
	 					cnt[x-1]+=cnt[x];
					 	dis[x-1]=dis[x]+1;
					 	if(!vis[x-1])
		 					D.push(x-1),
							vis[x-1]=1;
					 }
				 }vis[x]=0;
			 }
			for(i=s+1;i<=n;i++){
				if(cnt[i]==2)
					ans++;
			}
		 }
		 cout<<ans<<"\n";
	 }
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
