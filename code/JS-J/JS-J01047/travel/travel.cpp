#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long n,m;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	n=s1[0]*10+s1[1];
	m=s2[0]*10+s2[1];
	if(n==m){
		cout<<1;
	}
	else{
		cout<<"000"<<endl;
		return 0;
	}
	a=s1[2];
	b=s2[2];
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C'){
			cout<<1;
		}
		else{
			cout<<"00"<<endl;
			return 0;
		}
	}
	else{
		if(b=='F'||b=='D'){
			cout<<1;
		}
		else{
			cout<<"00"<<endl;
			return 0;
		}
	}
	if(a+1==b||a-1==b){
		cout<<1<<endl;
	}
	else{
		cout<<0<<endl;
	}
	return 0;
}
