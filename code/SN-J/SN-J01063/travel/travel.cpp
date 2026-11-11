#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b;
	string n,m;
	cin>>a>>n>>b>>m;
	//bool a1,b1,c1,d1;
	if(a==b) cout<<1;
	else cout<<0;
	if((n[0]==m[0]&&n[1]==m[1])&&(a==b)) cout<<1;
	else cout<<0;
	if(((n[2]<='C'&&m[2]<='C')||(n[2]=='F'&&m[2]=='E'))&&(n[0]==m[0]&&n[1]==m[1])&&(a==b))  cout<<1;
	else cout<<0;
	if(((n[2]=='A'&&m[2]=='B')||(n[2]=='B'&&m[2]=='C')||(n[2]=='F'&&m[2]=='E'))&&(n[0]==m[0]&&n[1]==m[1])&&(a==b)) cout<<1;
	else cout<<0; 
	fclose(stdin);fclose(stdout);
	return 0;
} 
