#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int a1,b1;
char a[3],b[3];
int t1,t2,t3,t4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a>>b1>>b;
	if(a1==b1) t1=1;
	if(t1==1&&a[0]==b[0]&&a[1]==b[1]) t2=1;
	if(t2==1){
		if(a[2]=='A'||a[2]=='B'||a[2]=='C'){
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				t3=1;
			}
		}
		if(a[2]=='D'||a[2]=='E'){
			if(b[2]=='D'||b[2]=='E'){
				t3=1;t4=1;
			}
		}
	}
	if(t3==1){
		if(a[2]=='A'&&b[2]=='B') t4=1;
		if(a[2]=='B'&&b[2]=='A') t4=1;
		if(a[2]=='B'&&b[2]=='C') t4=1;
		if(a[2]=='C'&&b[2]=='D') t4=1;
	}
	cout<<t1<<t2<<t3<<t4;
	return 0;
}

