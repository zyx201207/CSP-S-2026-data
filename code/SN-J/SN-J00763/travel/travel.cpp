//SN-J00763 西安交通大学附属中学 胡妍馨 
#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel5.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(s2[2]<='c' && s1[2]<='c') cout<<1;
	else if(s1[2]>='d' && s2[2]>='d') cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
