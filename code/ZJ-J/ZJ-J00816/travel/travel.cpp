#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool tong;
	if(c1==c2){
		tong=1;
		cout<<1;
	}else{
		tong=0;
		cout<<0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&tong){
		cout<<1;
	}else{
		cout<<0;
	}
	bool flag;
	if(tong&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))){
		flag=1;
		cout<<1;
	}else{
		flag=0;
		cout<<0;
	}
	if(flag){
		if(abs(s2[2]-s1[2])==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	return 0;
}