#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,n;string b,m;
	int s,s1;
	cin>>a>>b>>n>>m;
	int ja=0,jb=0,jc=0,jd=0;
	if(a!=n){
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	ja=1;
	
	s=(b[0]+b[1]);
	s1=(m[0]+m[1]);
	if(s1!=s){
		cout<<1000;
		return 0;
	}
	jb=1;
	
	if(b[2]=='F'&&m[2]=='D'||b[2]=='D'&&m[2]=='F' ||   b[2]=='C'&&m[2]=='B'||b[2]=='B'&&m[2]=='C'||   b[2]=='C'&&m[2]=='A'||b[2]=='A'&&m[2]=='C'||   b[2]=='B'&&m[2]=='A'||b[2]=='A'&&m[2]=='B'){
		jc=1;
	}
	else{
		cout<<1100;
		return 0;
	}
	
	if(b[2]=='F'&&m[2]=='D'||b[2]=='D'&&m[2]=='F' ||  b[2]=='C'&&m[2]=='B'||b[2]=='B'&&m[2]=='C'||   b[2]=='B'&&m[2]=='A'||b[2]=='A'&&m[2]=='B'){
		jd=1;
	}
	else{
		cout<<1110;
		return 0;
	}
	cout<<ja<<jb<<jc<<jd;
	fclose(stdin);
	fclose(stdout);
}
