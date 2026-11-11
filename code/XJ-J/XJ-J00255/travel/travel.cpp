#include <bits/stdc++.h>
using namespace std;
string cnt;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	char f='0';
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		f='1';
		cnt+=f;
	}else{
		f='0';
		cnt+=f;
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1]){
		f='1';
		cnt+=f;
	}else{
		f='0';
		cnt+=f;
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]=='D'&&s1[2]=='F'&&s2[2]=='D'&&s2[2]=='f'){
			f='1';
			cnt+=f;
		}else{
			f='0';
			cnt+=f;
		}
	}else{
		f='0';
		cnt+=f;
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'){
			f='1';
			cnt+=f;
		}
		if(s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'){
			f='1';
			cnt+=f;
		}
		if(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F'){
			f='1';
			cnt+=f;
		}
	}else{
		f='0';
		cnt+=f;
	}
	cnt+='0';
	for(int i=0;i<=3;i++){
		cout<<cnt[i];
	}
	return 0;
}
