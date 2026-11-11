#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500001;
const int M=300001;
int n,m,a[N],ans[M];
signed main(){
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++){
  	cin>>a[i];
  	ans[a[i]]+=i;
  }
  for(int i=1;i<=n;i++){
  	int vis[3001]={};
  	int vis2[3001]={};
  	for(int j=i;j<=n;j++){
  	  if(vis[a[j]]==0){
  	    vis[a[j]]=1;	
	  }
	  else{
	  	vis[a[j]]=0;
	  	int ni=j-1;
	  	vis2[j]=1;
	  	ans[a[j]]--;
	  	while(ni>=i&&a[ni]!=a[j]){
	  		if(vis2[ni]==0){
	  			ans[a[ni]]--;
	  			vis[a[ni]]=0;
			  }
	  		
	  		ni--;
		  }
	  }
	}
  }
  for(int i=1;i<=m;i++){
  	cout<<ans[i]<<' ';
  }
  return 0;
}
