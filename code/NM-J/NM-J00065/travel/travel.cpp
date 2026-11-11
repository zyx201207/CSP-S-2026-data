#include<bits/stdc++.h>
using namespace std;
struct seat{
	string cx,zw; 
};
int jdz(int aaa){
	return aaa>=0?aaa:-aaa;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	seat R,X;bool a1=false,a2=false,a3=false,a4=false;
	cin>>R.cx>>R.zw>>X.cx>>X.zw;
	a1=R.cx==X.cx;
	a2=R.zw[0]==X.zw[0]&&R.zw[1]==X.zw[1]&&a1;
	a3=((R.zw[2]<='C'&&X.zw[2]<='C')||(R.zw[2]>'C'&&R.zw[2]<='F'&&X.zw[2]>'C'&&X.zw[2]<='F'))&&a2;
	a4=jdz(R.zw[2]-X.zw[2])==1&&a3;
	cout<<a1<<a2<<a3<<a4;
	return 0;
} 
