#include<bits/stdc++.h> 
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,a1,a2,t1,t2;
	cin>>s1>>s2>>a1>>a2;
	if(s1==a1){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	t1=s2[0]+s2[1];
	t2=a2[0]+a2[1];
	if(t1==t2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((s2[2]<='C'&&a2[2]<='C')||(s2[2]>='D'&&a2[2]>='D')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	int t = s2[2]-a2[2];
	if(abs(t)==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
