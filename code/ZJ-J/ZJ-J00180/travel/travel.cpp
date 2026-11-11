#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool flag=0;
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<0;
		flag=1;
	}
	char t1=s1[0],t2=s2[0];
	char r1=s1[1],r2=s2[1];
	if(t1==t2&&r1==r2&& !flag)cout<<1;
	else{
		cout<<0;
		flag=1;
	}
	char a1=s1[2];
	char a2=s2[2];
	if(((a1=='A'&&a2=='B')||(a1=='A'&&a2=='C')||(a1=='B'&&a2=='A')||(a1=='B'&&a2=='C')||(a1=='C'&&a2=='B')||(a1=='C'&&a2=='A')||(a1=='D'&&a2=='E')||(a1=='E'&&a2=='D'))&&!flag)cout<<1;
	else{
		cout<<0;
		flag=1;
	}
	if(((a1=='A'&&a2=='B')||(a1=='B'&&a2=='C')||(a1=='D'&&a2=='E')||(a1=='B'&&a2=='A')||(a1=='C'&&a2=='B')||(a1=='E'&&a2=='D'))&&!flag)cout<<1;
	else cout<<0;
	
	
	return 0;
}