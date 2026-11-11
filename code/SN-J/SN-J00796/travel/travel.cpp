//考号:SN-J00796 学校：西安市临潼区铁炉初级中学 姓名：孙博元 
#include<bits/stdc++.h>
using namespace std;
bool a,b,c,d;
int n,m;
string n2,m2;
int main(){
	freopen("travel.in", "r" , stdin);
	freopen("travel.out", "w", stdout);
	cin>>n>>n2>>m>>m2;
	if(n==m){
		a=true;
	}else{
		a=false;
	}
	if(n2[0]==m2[0]&&n2[1]==m2[1]&&a==true){
		b=true;
	}else{
		b=false;
	}
	if((n2[2]=='D'&&m2[2]=='C'||n2[2]=='C'&&m2[2]=='D')||b!=true||a!=true){
		c=false;
	}else{
		c=true;
	}
	if(c==true&&abs(n2[2]-m2[2])==1){
		d=true;
	}else{
		d=false;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
