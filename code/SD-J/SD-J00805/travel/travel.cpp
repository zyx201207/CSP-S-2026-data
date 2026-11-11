#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>c2>>c3>>c4;
	if (c1==c3){
		cout<<1;
	}
	else if (c1!=c3){
		cout<<0<<0<<0<<0<<"\n"; 
		return 0;
	}
	if (c2.substr(0,2)==c4.substr(0,2)){
		cout<<1;
	}
	else {
		cout<<0<<0<<0<<"\n"; 
		return 0;
	}
	int a=c2[2]-'A',b=c4[2]-'A';
	if (a>=0&&a<=2){
		if (b>=0&&b<=2){
			cout<<1;
		}
		else {
			cout<<0<<0;
			return 0;
		}
	}
	else {
		if (b>2){
			cout<<1;
		}
		else {
			cout<<0<<0;
			return 0;
		}
	}
	cout<<(abs(a-b)==1);
}
