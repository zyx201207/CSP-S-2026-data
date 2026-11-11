#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans=0,n; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=n;i++){
		if(n-=i==0){
			ans+=1000;
		}else{
			ans+=0000;
		}
		if(i-=n==0){
			ans+=0100;
		}else{
			ans+=0000;
		}
	}
	cout<<ans;
	return 0;
}
