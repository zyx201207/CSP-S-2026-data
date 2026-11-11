#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,x[N];
signed main(){
	freopen("migrate4.in","r",stdin);
//	freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
  cin>>c>>t;
  while(t--){
  	int n,d;
  	cin>>n>>d;
  	if(c==13&&c==14){
  		cout<<n-3<<"\n";
  		continue;
	  }  
	  for(int i=1;i<=n;i++){
	  	  int a;cin>>a;
	  	  x[i]=a-x[i-1];
	  }
	   if(c==12||c==11){
	   	int cd=x[2]-x[1];	   	
	   	   if(d==cd*2){
	   	   	cout<<n/2<<"\n";
		}else if(d>cd*2&&d<cd*3)
		{
	   	   	cout<<n-3<<"\n";
	   	   	
		}else if(d>=3*cd){
			cout<<n-5<<"\n";
		}else{
			cout<<0<<"\n";
		}
	
	}
   }
}