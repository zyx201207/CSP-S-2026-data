#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int man=2000005;
int c,t,n,len[man];ll a[man],d,dp[5005],sum_dp[5005],ans=0ll;
int id[5005],L[5005],R[5005],las[5005];
void solve(){
	cin>>n>>d;ans=0ll;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++) len[j]=las[j]=L[j]=R[j]=id[j]=0;
		int step=1,lst=i,lim=n;
		for(int j=i+1;j<=n;j++) if(a[j]-a[j-1]>d){lim=j-1;break;}
		for(int j=i+1;j<=lim;j++){
			if(a[j]-a[lst]<=d) las[j]=lst;
			else{
				while(a[j]-a[lst]>d) lst++;
				las[j]=lst;
			}
		}
		for(int j=i+1;j<=lim;j++) len[j]=len[las[j]]+1;
//		for(int j=i+1;j<=lim;j++){
//			if(a[j]-a[lst]<=d) len[j]=step;
//			else{step++;lst=j-1;len[j]=step;}
//		}

//		for(int j=i+1;j<=lim;j++) cout<<len[j]<<' ';cout<<'\n';

		step=0;len[i-1]=-1;lst=i-1;
		for(int j=i;j<=lim;j++){
			if(len[j]!=len[j-1]){
				step++;lst=j;L[step]=j;id[len[j]]=step;
				while(len[lst]==len[j]&&lst<=lim){
					R[step]=lst;
					lst++;
				}
			}
		}

		for(int j=1;j<=lim;j++) dp[j]=sum_dp[j]=0ll;dp[i]=sum_dp[i]=1ll;
		for(int j=i+1;j<=lim;j++){
//			int loc;
//			for(int k=i;k<j;k++){
//				if(a[j]-a[k]<=d&&len[k]==len[j]-1){
//					cout<<"k="<<k<<' ';
////					loc=k;break;
//				}
//			}
//			cout<<'\n';
			//此处 k 在一个区间中, 可以简单维护 
//			int l=las[j],r=R[id[len[j]-1]];
			int l=max(las[j],L[id[len[j]-1]]),r=R[id[len[j]-1]];
			if(l<=r){
//				for(int k=l;k<=r;k++) dp[j]+=dp[k];
				dp[j]=sum_dp[r]-sum_dp[l-1];	
			}
			else dp[j]=0;
			sum_dp[j]=sum_dp[j-1]+dp[j];
		}
//		for(int j=i+1;j<=lim;j++) cout<<dp[j]<<' ';cout<<'\n';
		for(int j=i+1;j<=lim;j++) if(dp[j]==2ll) ans++;//cout<<"j="<<j<<'\n';
//		cout<<"ans="<<ans<<'\n';
	}
	cout<<ans<<'\n';//cout<<"--------------\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
//Oct31==Dec25?
/*
暴力耍起
但是并不好写
首先如果我每次跳跃就跳到能跳到的最远点，那必然是一条最优路径
要求恰好两条最优路径 
标算可能是 dp?
找不到刻画 (u,v) 合法的充要条件????

0 1
5 2
1 2 3 4 5

*/