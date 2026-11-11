#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,t3,t4;
char t1,t2;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<=s1.size()-2;i++){
    	t3+=s1[i];
    	t4+=s2[i];
	}
	t1=s1[s1.size()-1];
	t2=s2[s2.size()-1];
	if(c1==c2){
		a=1;
	}
	if(a==1&&t3==t4){
		b=1;
	}
	if(b==1&&(t1==t2+1||t2==t1+1||t1==t2+2||t2==t1+2)){
		c=1;
	}
	if(c==1&&(t1=='A'&&t2=='B')||(t1=='C'&&t2=='B')||(t1=='D'&&t2=='F')){
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}