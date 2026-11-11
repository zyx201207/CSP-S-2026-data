#include <bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
bool pd(char a,char b){
	int fa,fb;
	if(a=='A'||a=='B'||a=='C') fa=1;
	else fa=2;
	if(b=='A'||b=='B'||b=='C') fb=1;
	else fb=2;
	return fa==fb;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			char aa=s1[2],bb=s2[2];
			if(pd(aa,bb)){
				cout<<1;
				if(abs(aa-bb)==1&&!(aa=='C'&&bb=='D'||aa=='D'&&bb=='C')||aa=='D'&&bb=='F'||aa=='F'&&bb=='D') cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
/*
AC
ÆÀ²â»ú±£ÓÓÎÒ 
*/
