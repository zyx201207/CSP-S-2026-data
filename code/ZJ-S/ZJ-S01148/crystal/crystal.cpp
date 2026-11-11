#include<bits/stdc++.h>
using namespace std;
int n,m,b[5002][5002],ans;	
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a;
	cin>>n>>m;
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=n;j++){
    		b[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a;
		b[i][0]=a;
		b[0][i]=a;
	}
    for(int i=1;i<=n;i++){
       int cnt=0,sum=0;
	   for(int j=1;j<=n;j++){
	   	  if(b[0][j]<=b[i][0]){
			 sum++;
			 cnt+=b[i][0]-b[j][0];
		  } 
	   }
	   if(cnt<=m){
	   	 ans=max(sum,ans);
	   }  	  
	}
    cout<<ans;
    return 0;
}