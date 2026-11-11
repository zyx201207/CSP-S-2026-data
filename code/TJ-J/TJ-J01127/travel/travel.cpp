#include<bits/stdc++.h>
using namespace std;
int s1[10],s2[10];
int main(){
	freopen("travel.in","r",stdin);
	freoprn("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	int a,b,c,d;
	int e,f;
	if(c1!=c2){
		cout<<"0";
	}else if(c1=c2){
		cout<<"1";
	}
	int l=s1.size();
	for(int i=1;i<=l;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			 a=s1[0];
			 b=s1[1];
			 e=s1[2];
		}
	}
	int k=s2.size();
	for(int i=1;i<=k;i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			 c=s2[0];
			 d=s2[1];
			 f=s2[2];
		}
	}
	if(a==c&&b==d){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if((a==c&&b==d)&&(e<=67&&f<=67)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if((a==c&&b==d)&&(e<=67&&f<=67)&&(e+1==f||e-1==f)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}

