#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		f = 1;
	}else{
		cout<<"0";
		f = 0;
	}
	if(f==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		f = 1;
	}else{
		cout<<"0";
		f = 0;
	}
	char a = s1[2];
	char b = s2[2];
	if(f==1&&((a-'A'<=2)&&(b-'A'<=2)||(a-'A'>2)&&(b-'A'>2))){
		cout<<"1";
		f = 1;
	}else{
		cout<<"0";
		f = 0;
	}
	if(f==1&&abs(a-b)==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}