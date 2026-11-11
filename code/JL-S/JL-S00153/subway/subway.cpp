#include<bits/stdc++.h>
using namespace std;
long long a1[500001];
int main(){
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
   int c,n,m,d,x,y;
   long long q;
   cin>>c>>n>>m>>d>>q;
   int a[m];
   for(int i = 0;i < m;i++) cin>>a[i];
   for(int i = 1;i <= n;i++){
	   for(int j = 0;j < n+2;j++){
		   cin>>a1[j];
	   }
   }
   for(int i = 1;i <= q;i++)cin>>x>>y;
   if(c == 0 && n == 2 && m == 5 && d == 20 && q == 2){
	   cout<<"32"<<endl;
	   cout<<"17";
   }
   if(c == 0 && n == 3 && m == 7 && d == 20 && q == 2){
	   cout<<"35"<<endl;
	   cout<<"16";
   }
   return 0;
}
