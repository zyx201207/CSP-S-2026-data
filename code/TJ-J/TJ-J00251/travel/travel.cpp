#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in ","r",stdin);
	freopen(" travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);			
	static long long c1,s1,c2,s2,ans;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=2;i++){
		if(c1!=c2){
			ans=0;
			cout<<1111;
			break;
		}
		if(i==1){
		 ans=1;
		 cout<<1110;
		 continue;
		 }
		 if(ans==1){
		 	for(int i=0;i<=2;i++){
		 		if(s1!=s2){
		 			cout<<1110;
					 break;
				 }
				 if(i==1){
				 	ans==1;
				 	cout<<1; 
				 }
			 }
			char m=s1,n=s2;
			
			if(ans==1){
				cout<<1;
				}								
			}
		 } 
		 for(int i=1;i<4;i++){
				ans++;
		 }

	return 0;
	} 
