#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1!=a2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int x=0,y=0,n1=b1.size(),n2=b2.size();
	for(int i=0;i<n1;i++){
		if(b1[i]<='9'&&b1[i]>='0'){
			x=x*10+b1[i]-'0';
		}
	}
	for(int i=0;i<n2;i++){
		if(b2[i]<='9'&&b2[i]>='0'){
			y=y*10+b2[i]-'0';
		}
	}
	char a=b1[n1-1],b=b2[n2-1];
	if(x!=y){
		cout<<"000";
		return 0;
	}
	cout<<1;
	bool f1=0,f2=0;
	if(a=='A'||a=='B'||a=='C')f1=1;
	else f1=0;
	if(b=='A'||b=='B'||b=='C')f2=1;
	else f2=0;
	if(f1!=f2){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(a=='A'){
		if(b=='B')cout<<1;
		else cout<<0;
	}
	if(a=='B'){
		if(b=='A'||b=='C')cout<<1;
		else cout<<0;
	}
	if(a=='C'){
		if(b=='B')cout<<1;
		else cout<<0;
	}
	if(a=='D'){
		if(b=='F')cout<<1;
		else cout<<0;
	}
	if(a=='F'){
		if(b=='D')cout<<1;
		else cout<<0;
	}
	return 0;
}

