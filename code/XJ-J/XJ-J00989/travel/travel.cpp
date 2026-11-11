#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,c1,s,s1;
	cin>>c>>s>>c1>>s1;
	bool f=true;
	for(int i=0;i<2;i++){
		if(c[i]!=c1[i]){
			f=false;
			break;
		}
	}
	if(f==true){
		cout<<1;
	}
	else{
		cout<<0;
	}
	int a=0,b=0;
	for(int i=0;i<2;i++){
		a=(int)a*10+s[i]-'0';
		b=(int)b*10+s1[i]-'0';
	}
	if(a==b&&f==true){
		cout<<1;
	}
	else{
		cout<<0;
	}
	char aa,bb;
	aa=s[2];
	bb=s1[2];
	if(aa>='D'&&bb>='D'&&a==b&&f==true){
		cout<<11;
	}
	else if(aa<'D'&&bb<'D'&&a==b&&f==true){
		cout<<1;
		if(aa+1==bb||bb+1==aa){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if((aa=='C'&&bb=='D')||(aa=='D'&&bb=='C')){
		cout<<"00";
	}
	else{
		cout<<"00";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}