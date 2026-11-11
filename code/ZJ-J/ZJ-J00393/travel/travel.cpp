#include<bits/stdc++.h>
using namespace std;
int n,p;
string m,q;
string a,b;
char s,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>p>>q;
	if(n!=p){
		cout<<"0000";
		return 0;
	}
	cout<<'1';
	a+=m[0];
	a+=m[1];
	b+=q[0];
	b+=q[1];
	if(a!=b){
		cout<<"000";
		return 0;
	}
	cout<<'1';
	s=m[2];
	t=q[2];
	if(s>='A'&&s<='C'&&t>='D'&&t<='F'||t>='A'&&t<='C'&&s>='D'&&s<='F'){
		cout<<"00";
		return 0;
	}
	cout<<'1';
	if(s=='D'||s=='F'||abs(s-t)==1){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	return 0;
}
//Trick||Treat!