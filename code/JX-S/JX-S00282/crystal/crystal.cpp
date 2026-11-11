#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum,ans=-100;
int main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
     cin>>n>>m;
     for(int i=1;i<=n;i++){
         cin>>a[i];
     }
     sort(a+1,a+1+n);
     for(int j=n;j>=1;j--){
         sum=0;
         for(int w=j;w>=1;w--){
			 if(sum+a[j]-a[w]>=m){
				 ans=max(ans,j-w+1);
				 break;
         }
         sum+=a[j]-a[w];
       }
     }
     cout<<ans<<endl;
     return 0;
}
