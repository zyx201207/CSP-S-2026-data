#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f1,f2,f3,f4;
char r1,r2,r3,x1,x2,x3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	r1=s1[0];
	r2=s1[1];
	r3=s1[2];
	x1=s2[0];
	x2=s2[1];
	x3=s2[2];
	if(c1==c2){
		f1=1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(r1==x1&&r2==x2){
		f2=1;
	}
	else{
		cout<<"1000";
		return 0;
	}
	if(r3=='D')
	{
		if(x3=='F'){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	if(x3=='D')
	{
		if(r3=='F'){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	if(r3=='A'||r3=='B'||r3=='C'){
		if(x3=='A'||x3=='B'||x3=='C'){
			f3=1;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	if(x3=='A'||x3=='B'||x3=='C'){
		if(r3=='A'||r3=='B'||r3=='C'){
			f3=1;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	if(r3=='A'){
		if(x3=='B'){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1110";
			return 0;
		}
	}
	if(x3=='A'){
		if(r3=='B'){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1110";
			return 0;
		}
	}
	if(r3=='C'){
		if(x3=='B'){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1110";
			return 0;
		}
	}
	if(x3=='C'){
		if(r3=='B'){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1110";
			return 0;
		}
	}
	if(r3=='B'){
		if(x3=='A'||x3=='C'){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1110";
			return 0;
		}
	}
	if(x3=='B'){
		if(r3=='A'||r3=='C'){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1110";
			return 0;
		}
	}
	return 0;
}
