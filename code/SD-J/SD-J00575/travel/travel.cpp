#include<bits/stdc++.h>
using namespace std;
int n,m;
string n1;
string m1;
int a[10005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>n1>>m>>m1;
	bool flagg=0;
	if(n==m) {
		cout<<"1";
		flagg=1;
	}
	else cout<<"0";
	char a=n1[2];
	char b=m1[2];
	bool flag=0;
	if(flagg&&n1[0]+n1[1]==m1[0]+m1[1]) {
		cout<<"1";
		flag=1;
		if((a<='C'&&b<='C')||(a>='D'&&b>='D')){
			
			cout<<"1";
		}else cout<<"0";
	}else cout<<"00";
	if(flag&&abs(a-b)==1&&!(a=='C'&&b=='D')&&!(a=='D'&&b=='C')){
		cout<<"1";
	}else cout<<"0";
	return 0;
}
