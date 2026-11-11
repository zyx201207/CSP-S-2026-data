#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int s_1=s1[0]+s1[1],s_2=s2[0]+s2[1];
	bool a=c1==c2,b=s_1==s_2,c=(s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D');
	if(a){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(a&&b){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(a&&b&&c){
		cout<<1;
	}else{
		cout<<0;
	}
	
	if(a&&b&&c&&(s1[2]+1==s2[2]||s1[2]-1==s2[2])){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}