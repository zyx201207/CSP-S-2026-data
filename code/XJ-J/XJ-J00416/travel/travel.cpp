#include <bits/stdc++.h>
using namespace std;
string s,c,s1,c1;
int a=0,b=0,f=0,d=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c==c1){
		a=1;
		string k="",z="";
		char m,w;
		for(int i=0;i<s.size();i++){
			if(s[i]>='0' && s[i]<='9'){
				k+=s[i];
			}
			if(s[i]>='A' && s[i]<='Z'){
				m=s[i];
			}
			if(s1[i]>='A' && s1[i]<='Z'){
				w=s1[i];
			}
			if(s1[i]>='0' && s1[i]<='9'){
				z+=s1[i];
			}
		}
		if(k==z){
			b=1;
			if((m=='A' || m=='B' || m=='C') && (w=='A' || w=='B' || w=='C')){
				f=1;
				int h=int(m)-int(w);
				abs(h);
				if(((m=='A' && w=='B')|| (m=='B' && w=='A')) || ((m=='B' && w=='C') || (m=='C' && w=='B'))){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else if((m=='D' || m=='F') && (w=='D' || w=='F')){
				cout<<"1111";
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}