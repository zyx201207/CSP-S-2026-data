#include<bits/stdc++.h>
using namespace std;
int c1,c2,num1,num2;
char a,b;
void inout(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
}
int main(){
	inout();
	cin>>c1>>num1>>a>>c2>>num2>>b;
	if(c1==c2)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(num1==num2)cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(a=='F')a='E';
	if(b=='F')b='E';
	int A=a-'C';
	int B=b-'C';
	if(A>0&&B>0)cout<<"1";
	else if(A<=0&&B<=0)cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(abs(A-B)==1)cout<<"1";
	else cout<<"0";
	return 0;
} 
