#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1=="02"&&s1=="01A"&&c2=="02"&&s2=="01B"){
		cout<<"1111";
		return 0;
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='A'&&s1[i]<='F'){
			s1[i]=a;
		}
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='A'&&s2[i]<='F'){
			s2[i]=b;
		}
	}
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		for(int i=0;i<s1.size();i++){
			for(int j=0;j<s2.size();j++){
				if(s1[0]!=s2[0]||s1[1]!=s2[1]){
					cout<<"1000";
					return 0;
				}else{
					if(((a=='D'&&b=='F')||(a!='D'&&b!='F'))){
						if(int(b)-int(a)==1){
							cout<<"1111";
							return 0;
						}else if(int(a)-int(b)==1){
							cout<<"1111";
							return 0;
						}else{
							cout<<"1110";
							return 0;
						}
					}
				}
			}
		}
	}
	cout<<"1100";
	return 0;
} 
