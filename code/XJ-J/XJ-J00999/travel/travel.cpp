#include<bits/stdc++.h>
using namespace std;
int c=0,cc=0;//车厢
string s,ss;//座位号
int a=0,aa=0;//列
int b=0,bb=0;//座
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	a=(s[0]-'0')*10+(s[1]-'0');
	aa=(ss[0]-'0')*10+(ss[1]-'0');
	if(s[2]=='A'){
		b=1;
	}
	if(s[2]=='B'){
		b=2;
	}
	if(s[2]=='C'){
		b=3;
	}
	if(s[2]=='D'){
		b=4;
	}
	if(s[2]=='F'){
		b=5;
	}
	if(ss[2]=='A'){
		bb=1;
	}
	if(ss[2]=='B'){
		bb=2;
	}
	if(ss[2]=='C'){
		bb=3;
	}
	if(ss[2]=='D'){
		bb=4;
	}
	if(ss[2]=='F'){
		bb=5;
	}
	if(c==cc){
		cout<<"1";
		if(a==aa){
			cout<<"1";
			if((b<=3&&bb<=3)||(b>3&&bb>3)){
				cout<<"1";
				if(abs((b-bb))==1){
					cout<<"1";
				}else{
					cout<<"0";
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
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}