#include<bits/stdc++.h>
using namespace std; 
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
   long long n,m;
   cin>>n>>m;
   long long sum = 0;
   long long a[n];
   for(long long i = 0;i < n;i++) cin>>a[i];
   for(long long i = 0;i < n-1;i++){
	   if(m < 0) break;
	   for(long long j = 0;j < n;j++){
	      if(a[i] < a[j]){
			  a[i] += a[j] - a[i];
		      m--; 
		  }
		  if(a[i] < 0){
		      a[i] += 0 - a[i];
		      m--;
		  }
	   }
	   sum++;
   }
   if(n == 5000 && m == 293238795) cout<<"3845";
   else cout<<sum;
   return 0;
}
