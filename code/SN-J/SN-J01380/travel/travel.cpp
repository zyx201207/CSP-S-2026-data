#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
long long flag,flag1,flag2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	long long c=0,d=0;
	for(int i=0;i<=1;i++){
		c=c*10+int(c1[i]-'0');
		d=d*10+int(c2[i]-'0');
	}
	if(c==d){
		cout<<1;
	}
	else{
		cout<<0;
		flag1=1;
	}
	long long a,b;
	for(int i=0;i<=1;i++){
		a=a*10+s1[i]-'0';
		b=b*10+s2[i]-'0';
	}
	if(a==b && flag1==0){
		cout<<1;
	}
	else{
		cout<<0;
		flag2=1;
	}
	char a1=s1[2];
	char b1=s2[2];
	if((a1<='C' && b1<='C') || (a1>'C' && b1>'C')){
		if(flag2==0){
			cout<<1;
		}
		else{
			cout<<0;
			flag=1;
		}
	}
	else{
		cout<<0;
		flag=1;
	}
	if(a1+1==b1 || a1-1==b1){
		if(flag==0){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;	
}
