#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,len,step,t;
int line[500000],ans[500000];
int a[500000],maxn=-1;
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>t;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int bb=1;
	int mm=n;
	while(mm--){
		for(int i=bb;i<=n;i++){
			line[i]=a[i];
		   for(int j=bb;j<=i;j++){
			  if(line[j]==line[i]&&line[i]!=-1&&j!=i){
				for(int k=j;k<=i-1;k++){
					line[k]=-1;
				}
			 }
		 }
	   }
	   for(int i=1;i<=n;i++){
	   	    if(line[i]!=-1){
	   	  	 ans[line[i]]++;
		    }
		    line[i]=-1;
	   }
	   bb++;
	}
	for(int i=1;i<=t;i++){
	   	cout<<ans[i]<<" ";
	}
}
