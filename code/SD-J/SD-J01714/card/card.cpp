#include<bits/stdc++.h>
using namespace std;
long long a[520000],d[520000];
long long n,m,s[520000],ans[520000],k[320000];
int f[520000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	 for(int j=1;j<=n;j++){
      s[j]=0; f[j]=0; d[j]=0;
	  }
 for(int j=i;j<=n;j++){	
 	  if(f[a[j]]){
 	  	d[f[a[j]]]++; d[j]--;
	  }
	  f[a[j]]=j;
 }
      for(int j=i;j<=n;j++){
      	s[j]+=s[j-1]+d[j];
      	ans[j]+=s[j];
	  }
	 
}
for(int i=1;i<=n;i++){
      k[a[i]]=max(k[a[i]],(i-ans[i]));
	  }
	  for(int i=1;i<=m;i++){
	  	cout<<k[i]<<' ';
	  } 

	return 0;
} 
  
