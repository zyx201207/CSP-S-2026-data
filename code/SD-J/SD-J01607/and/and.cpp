#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,m,ans[1000][1000],a[100000000],maxn=-100,anns;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
   	    cin>>a[i];
   }
   int cot=0;
   sort(a,a+n);
   for(int i=1;i<=n;i++){
       cot=0;
   	    while(a[i]>0){
   	    	cot++;
   	    	ans[i][cot]=a[i]%2;
   	    	a[i]/=2;
		   }
   }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=maxn;j++){
    	  if(ans[i][j]==ans[i-1][j]){
    	  	anns+=pow(2,j);
		  }
		}
		if(anns>maxn)maxn=anns;
	}
	cout<<maxn;
}
