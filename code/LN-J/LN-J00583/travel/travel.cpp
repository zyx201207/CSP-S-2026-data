#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string a="",b="";
	char a1,b1;
	bool o1=false,o2=false;
	if(c1==c2){
		cout<<'1';
		for(int i=0;i<s1.size();i++){
			if(s1[i]>='0'&&s1[i]<='9') a+=s1[i];
			if(s1[i]>='A'&&s1[i]<='F') a1=s1[i];
		}
		for(int j=0;j<s2.size();j++){
			if(s2[j]>='0'&&s2[j]<='9') b+=s2[j];
			if(s2[j]>='A'&&s2[j]<='F') b1=s2[j];
		}
		if(a==b){
			cout<<'1';
			if(a1>='A'&&a1<='C'&&b1>='A'&&b1<='C') o1=true; 
			if(a1>='D'&&a1<='F'&&b1>='D'&&b1<='F') o2=true;
			if(o1||o2){
				cout<<'1';
				if(o2){
					cout<<'1';
					return 0;
				}
				if(a1=='A'||a1=='C'){
					if(b1=='B'){
						cout<<'1';
						return 0;
					}
					else{
						cout<<'0';
						return 0;
					}
				}
				if(a1=='B'){
					if(b1=='A'||b1=='C'){
						cout<<'1';
						return 0;
					}
					else{
						cout<<'0';
						return 0;
					}
				}
				
			}else{
					cout<<"00";
					return 0;
				}
			}else{
				cout<<"000";
				return 0;
			}
		}else{
		cout<<"0000";
		return 0;
	}
}

