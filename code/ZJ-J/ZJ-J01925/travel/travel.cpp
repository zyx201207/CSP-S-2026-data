#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
char n,m;
bool st1,st2,ok;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else {
		cout<<"0000";
		fclose(stdin);
	    fclose(stdout);
	    return 0;
	}
	a=(s1[0]-48)*10+s1[1]-48;
	b=(s2[0]-48)*10+s2[1]-48;
	n=s1[2];
	m=s2[2];
	if(a==b&&!ok)cout<<1;
	else {
		cout<<0;
		ok=1;
	}
	if(n=='F'||n=='D')st1=1;
	if(m=='F'||m=='D')st2=1;
	if(st1==st2&&!ok)cout<<1;
	else {
		cout<<0;
		ok=1;
	}
	if((a+1==b&&n==m)||(a-1==b&&n==m)||(a==b&&n+1==m)||(a==b&&n-1==m)){
		if((n=='D'&&m=='C')||(n=='C'&&m=='D'))cout<<0;
		else cout<<1;
	}
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}