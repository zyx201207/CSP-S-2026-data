#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f1=1;
		string s12=s1.substr(0,2),s22=s2.substr(0,2);
		if(s12==s22){
			f2=1;
			char s1l=s1[2],s2l=s2[2];
			if((s1l<='C'&&s2l<='C')||(s1l>'C'&&s2l>'C')){
				f3=1;
				int c=abs(s1l-s2l);
				if((s1l=='C'&&s2l=='D')||(s1l=='D'&&s2l=='C')){
				}else if(c==1){
					f4=1;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
