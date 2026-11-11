#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>c2>>s1>>s2;
	if(c1=c2){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	} 
	string x=c2.substr(0,2),y=s2.substr(0,2);
	if(x==y){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	char n=c2.substr(2,1);
	char m=s2.substr(2,1);
	if(n!='D'&&m!='F'&&n!='F'&&m!='D'||n!='B'&&m!='B') {
		cout<<1;
	}
	else{
		cout<<0;
		return 0;
	}
	if(n=='A'&&m=='C'||n=='C'&&m=='A') {
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
    }
