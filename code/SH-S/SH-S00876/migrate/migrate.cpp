#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long c,t,n,d,x[N],dp[N][N],i,j,u,v;
long long o,p,q,ans;
int main(){
 freopen("migrate.in","r",stdin);
 freopen("migrate.out","w",stdout);
 cin>>c>>t;
 for(i=1;i<=t;i++){
  cin>>n>>d;
  for(j=1;j<=n;j++)cin>>x[j];
  ans=0;
  for(u=1;u<=n;u++){
   for(v=u+1;v<=n;v++){ 
    dp[u][0]=1;
    for(o=u+1;o<=v;o++){
     for(p=0;p<=v-u;p++)dp[o][p]=0;
	}
	for(o=u+1;o<=v;o++){
	 for(p=u;p<o;p++){
	  if(x[o]-x[p]<=d){
	   for(q=1;q<=v-u;q++){
	    if(dp[p][q-1]>=1)dp[o][q]+=dp[p][q-1];
	   }
	  }
	 }
	}
	for(o=1;o<=v-u;o++){
	 if(dp[v][o]>0){
	  if(dp[v][o]==2){
	   ans++;
	  }
	  break;
	 }
	}
   }
  }
  cout<<ans<<'\n';
 }
 return 0;
}
