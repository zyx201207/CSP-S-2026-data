#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	int num=0,st=0;
    for(int i=1;i<=n;i++){
    	int x=num;
    	x=x+(a[i]-a[i-1])*(st);
    	st++; 
    	 if(x>m){
    	 	while(x>m){
    	 		x=x-a[i]+a[i-st+1];
    	 		 st--;
			 }
			 num=x;
			 
		 }else{
		 	num=x;
		 }
    	ans=max(st,ans);
    	
	}
	
	
	cout<<ans;
	return 0;
} 
