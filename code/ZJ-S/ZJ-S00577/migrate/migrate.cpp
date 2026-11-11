#include<bits/stdc++.h>
const int slen=2e6+10;
using namespace std;
long long a[slen],n,m,ans;
long long dpl[slen],dps[slen];
void dfs(int l){
  for(int i=l;i<=n;i++){
  	int j=i-1;
  	while(a[i]-a[j]<=m&&j>=l){
  	  if(dpl[i]>dpl[j]+1){
  	    dpl[i]=dpl[j]+1;
  	    dps[i]=dps[j];
	  }
	  else if(dpl[i]==dpl[j]+1)dps[i]+=dps[j];
	  //cout<<i<<' '<<j<<' '<<dpl[i]<<' '<<dps[i]<<endl;
	  j--;
	}
	if(dps[i]==2)ans++;
  }
}
int main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  int t,c;
  cin>>c>>t;
  //cout<<c<<" "<<t<<endl<<endl;
  for(int o=1;o<=t;o++){
  	cin>>n>>m;
  	//cout<<n<<' '<<m<<endl;
  	bool f=1;
  	for(int i=1;i<=n;i++){cin>>a[i];}
  	for(int i=2;i<n;i++){
  	  if(a[i]-a[i-1]!=a[i+1]-a[i]){
  	  	f=0;
  	  	break;
	  }
	}
	if(n<=330){
	  ans=0;
	  for(int i=1;i<=n;i++){
	  	for(int j=1;j<=n;j++){
	  	  dpl[j]=0x7f7f7f7f;
	  	  dps[j]=0;
	    }
	    dps[i]=1;
	    dpl[i]=0;
	  	dfs(i);
	  }
	  cout<<ans<<'\n';
	}
  	else if(f==1){//A
  	  long long pr=a[2]-a[1];
  	  long long lm=m/pr;
  	  //cout<<m<<' '<<pr<<' '<<lm<<endl;
  	  if(lm<=1||n-2*lm+1<0)cout<<0<<'\n';
  	  else cout<<n-2*lm+1<<'\n';
	}
  }
  return 0;
}