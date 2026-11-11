#include <bits/stdc++.h>
using namespace std;
char ji;
long long a,n,shu=1,zhong,ans=0;
int zong[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a;
		cin>>ji;
		for(int i=1;i<=a;i++){
			zong[shu]=int(ji);
			shu++;
		}
	}
	shu--;
    if(shu%2==1){
    	zhong=(shu+1)/2;
    	for(int i=1;i<zhong;i++){
    		if(zong[i]!=zong[shu]){
    			ans++;
    			shu--;
			}
			else continue;
    		
	}
}
	else if(shu%2==0){
		zhong=shu/2;
    	for(int i=1;i<=zhong;i++){
    		if(zong[i]!=zong[shu]){
    			ans++;
    			shu--;
			}
			else {
				shu--;
				continue;
			}
    		
	}
	}
    cout<<ans;
    
} 
