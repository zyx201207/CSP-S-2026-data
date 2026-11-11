#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500009];
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);	
   int n;
   long long m;
   scanf("%d%lld",&n,&m);
   for(int i=1;i<=n;i++){
      scanf("%lld",&a[i]);
   }
   sort(a,a+n);
   int maxn=0;
   int l=1;
   long long sum=0;
   for(int i=1;i<=n;i++){
      sum+=(a[i]-a[i-1])*(i-l);
      while(sum>m){
	     sum-=a[i]-a[l];
	     l++;
	  }
	  maxn=max(maxn,i-l+1);
   }
   printf("%d",maxn);
   return 0;
}
