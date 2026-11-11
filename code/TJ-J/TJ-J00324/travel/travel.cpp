#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
char z[3]={'A','B','C'};
char y[2]={'D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<'1';
	else {
	cout<<"0000";
	return 0;}
	if(s1[1]==s2[1]){
		cout<<'1';
		bool f=0;
		int cnt=0,i1=-1,i2=-1;
		if(s1[2]<='C'&&s1[2]>='A'){
			for(int i=0;i<3;i++){
				if(s1[2]==z[i]||s2[2]==z[i]){
					if(i1!=-1)i2=i;
					else i1=i;
					cnt++;
				}
				
			}if(cnt>1&&i1!=-1&&i2!=-1){
					if(abs(i1-i2)==1)cout<<"11";
					else cout<<"10";
					return 0;
				}
				else {
					cout<<"00";
					return 0;
				}
			
	}
	else{
		for(int i=0;i<2;i++){
			if(s1[2]==y[i]||s2[2]==y[i]){
				if(i1!=-1)i2=i;
				else i1=i;
				cnt++;
			}
		}
		if(cnt>1&&i1!=-1&&i2!=-1){
					if(abs(i1-i2)==1)cout<<"11";
					else cout<<"10";
					return 0;
				}
				else {
					cout<<"00";
					return 0;
				}
		
	}
	}
	else{
		cout<<"000";
	}
	return 0;
}
