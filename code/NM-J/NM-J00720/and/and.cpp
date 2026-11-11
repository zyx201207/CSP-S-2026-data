#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("treval.in","r",stdin);
   freopen("treval.out","w",stdout);
   int n,m,a[2000];
   cin>>n>>m;
   if(m==1){
	   int maxn=0;
	   for(int i=0;i<n;i++){
	   cin>>a[i];
	   maxn=max(maxn,a[i]);
       }
       cout<<maxn;
   }
   fclose(stdin);
   fclose(stdout);
   return 0;
}
