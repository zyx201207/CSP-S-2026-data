#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int x1=0,x2=0;
	char t1,t2;
	bool f1=0,f2=0,f3=0,f4=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f1=1;
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			x1=x1*10+(s1[i]-'0');
		}
		if(s1[i]>='A'&&s1[i]<='Z'){
			t1=s1[i];
		}
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			x2=x2*10+(s2[i]-'0');
		}
		if(s2[i]>='A'&&s2[i]<='Z'){
			t2=s2[i];
		}
	}
	if(f1==1){
		if(x1==x2){
			f2=1;
		}
		if(abs(t1-t2)==1&&(t1!='D'&&t1!='C')&&f2==1){
			f4=1;
		}
	}
	if(f2==1){
		if(t1<='C'&&t2<='C'||t1>='D'&&t2>='D'){
			f3=1;
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
