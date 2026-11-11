#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		/*
		string t1=s1[0]+s1[1];
		string t2=s2[0]+s2[1];
		*/
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			cout<<1;
			char a=s1[2];
			char b=s2[2];
			if(((a!='C'||b!='D')&&(a!='D'||b!='C'))){
				cout<<1;
				if(abs(a-b)==1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
			//if(abs(a-b==1)&&(a!='C'||a!='D')&&(b!='C'||b!='D'))
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
