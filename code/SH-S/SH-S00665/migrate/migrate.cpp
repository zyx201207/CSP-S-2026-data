#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t,n,res,cnt;
ll d,ans,x[N];
void dfs(int pos,int to,int cur){
	if(cnt>2) return ;
	if(cur>res) return ;
	if(pos==to){
	  cnt++;
	  return ;
	}
	for(int i=pos+1;i<=to;i++)
	  if(x[i]-x[pos]<=d) dfs(i,to,cur+1);
	return ;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	  cin>>n>>d; ans=0;
	  for(int i=1;i<=n;i++) cin>>x[i];
	  if(n<=3){
	    cout<<"0"<<endl;
	    continue;
	  }
	  for(int i=1;i<=n;i++){
	    for(int j=i+3;j<=n;j++){
	      int pos=i; res=0,cnt=0;
	      for(int k=i;k<=j;k++){
	        if(x[k]-x[pos]<=d) continue;
	        pos=k-1,res++;
	      }
	      res++;
	      dfs(i,j,0);
	      if(cnt==2) ans++;
	    }
	  }
	  cout<<ans<<endl;
	}
	return 0;
}