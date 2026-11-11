#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,f;
char b1,b2;
int a1,a2,flag1=1,flag2=1;
int main(){
	freopen("traval.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		f+='1';
	}
	a1=(s1[0]-'0')*10+(s1[1]-'0');
	a2=(s2[0]-'0')*10+(s2[1]-'0');
	b1=s1[2];b2=s2[2];
	if(a1==a2){
		f+='1';
	}else{
		f+='0';
		flag1=0;
	}
	if(flag1){
		if(b1>='A'&&b1<='C'){
			if(b2>='A'&&b2<='C'){
				f+='1';
			}else{
				f+='0';
				flag2=0;
			}
		}else{
			if(b2>='D'&&b2<='F'){
				f+='1';
			}else{
				f+='0';
				flag2=0;
			}
		}
	}else{
		cout<<"1000";
		return 0;
	}
	if(flag1&&flag2){
		int m1=b1-'A',m2=b2-'A';
		if(abs(m1-m2)==1){
			f+='1';
		}else{
			f+='0';
		}
	}else{
		//cout<<1<<" ";
		f+='0';
	}
	cout<<f;
	
	
	return 0;
}
