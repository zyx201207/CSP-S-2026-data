#include<bits/stdc++.h>
using namespace std;
int a,b,s1_cnt,s_cnt;
string s,s1;
char c_s,c_s1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>s1;
	for(int i=0;i<2;i++){
		s_cnt+=s[i]-'0';
	}
	c_s=s[2];
	c_s1=s1[2];
	for(int i=0;i<2;i++){
		s1_cnt+=s1[i]-'0';
	}
	if(a==b) {
		cout<<1;
		if(s1_cnt==s_cnt){
			cout<<1;
			if(c_s>='A'&&c_s<='C'&&c_s1>='A'&&c_s1<='C'||c_s>='D'&&c_s<='F'&&c_s1>='D'&&c_s1<='F'){
				cout<<1;
				if(abs(c_s-c_s1)==1){
					cout<<"1";
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
