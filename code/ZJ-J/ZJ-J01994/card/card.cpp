#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+39;
int n,m;
int vis[maxn]={},in[maxn]={};
int dp[maxn],ans[maxn],a[maxn];
int main(){
	freopen("card.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[n]=1;
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=m;j++){
			vis[j]=0;
			in[j]=0;
		}
		for(int j=i;j<=n;j++){
			dp[j]++;
			if(vis[a[j]]>=1){
			//	cout<<j<<"text_"<<i<<"\n";
			//	cout<<a[j];
				for(int l=in[a[j]];l<=j-1;l++){
					dp[l]--;
				}
				for(int l=j;j<=n;j++){
					vis[a[l]]=0;
					in[a[l]]=l;
				}
				//cout<<"1202-39"<<"\n";
	      	}else{
	      		vis[a[j]]++;
			in[a[j]]=j;
			  }
		}
	}
	int ans[m];
	for(int i=1;i<=m;i++){
		ans[i]=0;
	}
	/*for(int i=1;i<=n;i++){
		cout<<"one-day tour:"<<dp[i]<<"\n";
	}*/
	dp[n]=n;
	for(int i=1;i<=n;i++){
		ans[a[i]]=max(ans[a[i]],dp[i]);
	//	cout<<"1202-"<<"2010:"<<i<<" 0621:"<<dp[i]<<"-39"<<'\n';
	//	cout<<"1202-"<<"2011:"<<i<<" 1202:"<<ans[a[i]]<<"-39"<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m){
			cout<<' ';
		}
	
	}
}