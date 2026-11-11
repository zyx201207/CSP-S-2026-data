#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
  	int a[10010];
  	int n,m,c,d;
  	cin>>n;
  	for(int i=0;i<=n;i++){
  		cin>>m;
  		a[i] = m;
  		c = i;
	  }
	  d = c/2;
	  cout<<a[d];
	return 0;
}