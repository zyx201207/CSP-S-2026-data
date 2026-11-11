#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=0,m=0,nn=0,mm=0;
	char a[4]={},b[4]={};
	cin>>n>>a>>m>>b;
	if(n==m){
		cout<<'1';
		nn=1;
	}
	else cout<<'0';
    if(a[0]==b[0]&&a[1]==b[1]&&nn==1){
    	cout<<'1';
    	mm=1;
	}
    else cout<<'0';
   if(a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C'&&mm==1||a[2]>='D'&&a[2]<='F'&&b[2]>='D'&&b[2]<='F'&&mm==1){
   	cout<<'1';
   	int y=1;
   }
   else cout<<'0';
   	if(a[2]=='A'&&b[2]=='B'&&mm==1||a[2]=='B'&&b[2]=='C'&&mm==1||a[2]=='D'&&b[2]=='F'&&mm==1||a[2]=='B'&&b[2]=='A'&&mm==1||a[2]=='C'&&b[2]=='B'&&mm==1||a[2]=='F'&&b[2]=='D'&&mm==1) cout<<'1';
    else cout<<'0';
	return 0;
}