#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
	}
	int lenb=s1.size();
	int lend=s2.size();
	string sz1,sz2;
	char zm1,zm2;
	for(int i=0;i<lenb;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			sz1=sz1+s1[i];
		}else{
			zm1=s1[i];
		}
	}
	for(int i=0;i<lend;i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			sz2=sz2+s2[i];
		}else{
			zm2=s2[i];
		}
	}
	if(sz1==sz2){
		b=1;
	}
	int f1=0,f2=0;
	if(zm1>='A'&&zm1<='C'){
		f1=1;
	}
	if(zm2>='A'&&zm2<='C'){
		f2=1;
	}
	if(f1==f2){
		c=1;
	}
	if(a==0){
		b=0;
	}
	if(b==0){
		c=0;
	}
	if(c==1){
		if(zm1-zm2==-1||zm1-zm2==1){
			d=1;
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
