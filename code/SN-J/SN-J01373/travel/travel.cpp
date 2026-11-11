#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
	}
	/*if(s1/10==s2/10){
		cout<<"1";
		if(s1%10+1==s2%10){
			cout<<"1";
		}else{
			
		}
	}*/
	return 0;
} 
