#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int z1,z2;
char b1,b2;
bool f=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>s1>>c1>>s2>>c2;
    z1=(c1[0]-'0')*10+(c1[1]-'0');
    z2=(c2[0]-'0')*10+(c2[1]-'0');
    b1=c1[c1.size()-1];
    b2=c2[c2.size()-1];
	if(s1==s2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1==s2&&z1==z2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1==s2&&z1==z2&&((b1>'C'&&b2>'C')||(b1<'D'&&b2<'D'))){
		f=true;
		cout<<1;
	}else{
		cout<<0;
	}
	if(f&&abs(int(b1)-int(b2))==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
