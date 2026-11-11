#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int c1,c2;
string s1,s2;
int pdc(char x){
	if(x=='A'||x=='B'||x=='C') return 1;
	return 2;
}
bool ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string h1,h2;
	char l1,l2;
	h1=s1[0]+s1[1];
	h2=s2[0]+s2[1];
	l1=s1[2];
	l2=s2[2];
	if(c1==c2){
		ans1=1;
		if(h1==h2){
			ans2=1;
			if(pdc(l1)==pdc(l2)){
				ans3=1;
				if(abs(l1-l2)==1) ans4=1;
			}
		}
	} 
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
} 
