#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200001;
int n,l=1,r;
int a[N],ans;
char b[N];
signed main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++){
  	cin>>a[i]>>b[i];
  	r+=a[i];
  }
  int sl=1,sr=n;
  while(l<r){
  	int x=min(a[sl],a[sr]);
  	if(b[sl]!=b[sr]){
  	  ans+=x;
	}
	if(a[sl]==a[sr]){
  	    sl++;
		sr--;	
	}
	else if(a[sl]>a[sr]){
		a[sl]-=x;
		sr--;	
	}
	else if(a[sl]<a[sr]){
		a[sr]-=x;
		sl++;	
	}
	l+=x;
	r-=x;
  }
  cout<<ans;
  return 0;
}
