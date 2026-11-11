#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<pair<int,int>>q;
int dis[1010][1010],g[1010][1010],dp[1010][1010][2],vis[1010000],a[1000100],t,n,m,c,d,Q,w[1000100],ll[1001000],rr[1000100],l1[100010],x[1000100],ans,nxt[1000100],lst1[100010],lst2[1000100],sec,last1;
vector<pair<int,int>>edges[10010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(lst1,0,sizeof lst1);
		memset(lst2,0,sizeof lst2);
		memset(ll,0,sizeof ll);
		memset(rr,0,sizeof rr);
		last1=sec=0;
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c<=6){
			int ans1=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(x[j]-x[i]<=d){
						g[i][j]=1;
						dis[i][j]=1;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					for(int k=i;k<=j;k++){
						if(dis[i][j]<dis[i][k]+dis[k][j]){
							dis[i][j]=dis[i][k]+dis[k][j];
							g[i][j]+=g[i][k]*g[j][k];
						}
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(g[i][j]==2)ans1++;
				}
			}
			cout<<ans1<<"\n";
			continue;
		}
//		if(c!=13&&c!=14){
			//最多改一处，距离不超过一
//			for(int i=1;i<n;i++){
//				nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
//			//	cout<<lst1[3]<<" "<<lst2[3]<<"\n";
//				if(!ll[nxt[i]])ll[nxt[i]]=i;
//				rr[nxt[i]]=i;
//				if(lst1[nxt[i]])lst2[nxt[i]]=lst1[nxt[i]],lst1[nxt[i]]=i;
//				else lst1[nxt[i]]=i;
//			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){
					if(x[i]-x[j]<=d){
						if(!ll[i])ll[i]=j;
						rr[i]=j;
					}
				}
			}
		//	for(int i=1;i<=n;i++){
		//		cout<<ll[i]<<" "<<rr[i]<<"\n";
		//	}
			for(int l=1;l<=n;l++){
				for(int r=l;r<=n;r++){
					if(x[l]+d>=x[r])dp[l][r][0]=1;
				}
			}
			for(int l=1;l<=n;l++){
				if(ll[l]!=0&&rr[l]!=0)dp[l][l][1]=dp[ll[l]][rr[l]][1];
				for(int r=l+1;r<=n;r++){
					if(ll[l]==0||rr[l]==0)continue;
					dp[l][r][0]=dp[ll[l]][rr[l]][0];
					dp[l][r][1]=dp[ll[l]][rr[l]][1];
					if(l+2>r){
						if(ll[l+1]<=rr[l])dp[l][r][1]+=dp[ll[l+1]][rr[l]][0];
					}
					else{
						if(ll[l+1]<=min(ll[l+2]-1,rr[l]))dp[l][r][1]+=dp[ll[l+1]][min(ll[l+2]-1,rr[l])][0];
					}
				}
			}
			for(int i=1;i<=n;i++){
				ans+=dp[i][i][1];
			//	cout<<dp[i][i][1]<<"\n";
			}
			cout<<ans<<"\n";
//			for(int i=2;i<n;i++){
////				if(nxt[i]==i){
////					last1=sec=0;continue;
////				}
//				if(x[nxt[i]]-x[i-1]<=d&&(i==2||x[nxt[i]]-x[i-2]>d)){
//					if(lst1[i]<lst2[i])swap(lst1[i],lst2[i]);
//					if(last1<lst1[i]){
//						sec=max(lst2[i],last1);
//						last1=lst1[i];
//					}
//					else{
//						sec=max(sec,lst1[i]);
//					}
////					sec=max(last1,lst2[i]);
////					last1=lst1[i];
//				}
//				ans+=last1-sec;
//				
//			}
//			cout<<ans<<"\n";
//		}
		
//		if(c==13||c==14){
//			int sum1=0,minn=1e9,xx,ans1=0;
//			for(int i=1;i<=n;i++){
//				if(max(x[i]-x[1],x[n]-x[i])<minn){
//					minn=max(x[i]-x[1],x[n]-x[i]);
//					xx=i;
//				}
//			}
//			for(int i=1;i<=n;i++){
//				sum1=0;
//				if(xx>=1&&x[xx-1]-x[i]<=d&&x[n]-x[xx-1]<=d)sum1++;
//				if(x[xx+1]-x[i]<=d&&x[n]-x[xx+1]<=d)sum1++;
//				if(xx>=2&&x[xx-2]-x[i]<=d&&x[n]-x[xx-2]<=d)sum1++;
//				if(x[xx+2]-x[i]<=d&&x[n]-x[xx+2]<=d)sum1++;
//				if(sum1==2)ans1++;
//			}
//			cout<<ans1<<"\n";
//		}
	}
	return 0;
}
/*
0 1 
6 2
-4 -3 -2 -1 3 6
*/
//d<7-1
//
//1 3 5 7
//d<9-1
//d>=5-1&&d>=9-5
//min(9-3,7-1)<=d<=max(9-3,7-1)
//1 3 5 7 9
//a1 a2 a3 a4 "a5" a6 a7 a8
//a1 a2 a4 a6 