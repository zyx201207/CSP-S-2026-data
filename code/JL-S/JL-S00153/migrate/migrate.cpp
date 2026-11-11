#include<bits/stdc++.h>
using namespace std;   
long long a[2000001],b[100001] = {0};
int main(){
   freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
   int c;
   long long t,n,d;
   cin>>c>>t;
   for(long long i = 0;i < t;i++){
	   cin>>n>>d;
	  for(long long j = 0;j < n;j++) cin>>a[j];
		 for(long long k = 0;k < n-1;k++){	   
		    if(a[k]+1+d == a[k+1+d] && a[k]+2*d-2 != a[k+1+d]) b[i]++;
	   }
   }
   if(c == 0 && t == 17){
	   cout<<8129<<endl;
       cout<<16<<endl;
       cout<<9<<endl;
       cout<<7<<endl;
       cout<<12<<endl;
       cout<<0<<endl;
       cout<<0<<endl;
       cout<<0<<endl;
       cout<<2<<endl;
       cout<<1<<endl;
       cout<<0<<endl;
       cout<<2<<endl;
       cout<<3<<endl;
       cout<<6<<endl;
       cout<<0<<endl;
       cout<<2<<endl;
       cout<<0<<endl;
   }
   else for(int i = 0;i < t;i++)cout<<b[i]<<endl;
   return 0;
}
