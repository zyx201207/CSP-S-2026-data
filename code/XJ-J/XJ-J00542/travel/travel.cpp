#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag;
int a[10];
int zh(char x) {
	if(x=='A')return 1;
	if(x=='B')return 2;
	if(x=='C')return 3;
	if(x=='D')return 4;
	if(x=='E')return 5;
	if(x=='F')return 6;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int aa=0,bb=0;
	if(c1==c2)a[1]=1;
	if(a[1]==0) {
		for(int i=1; i<=4; i++) {
			cout<<a[i];
		}
		return 0;
	}
	aa=(s1[0]-'0')*10+s1[1]-'0';
	bb=(s2[0]-'0')*10+s2[1]-'0';
	if(aa==bb)a[2]=1;
	char ss1=s1[2];
	char ss2=s2[2];
	int x=zh(ss1);
	int y=zh(ss2);
	if(x==4||x==5) {
		if(y==1||y==2||y==3)flag=1;
	}
	if(y==4||y==5) {
		if(x==1||x==2||x==3)flag=1;
	}
	if(!flag&&a[2]==1)a[3]=1;
	if(a[3]==0)a[4]=0;
	else if(aa!=bb)a[4]=0;
	else {
		int sum=abs(x-y);
		if(sum==1)a[4]=1;
	}
	for(int i=1; i<=4; i++) {
		cout<<a[i];
	}
	return 0;
}
