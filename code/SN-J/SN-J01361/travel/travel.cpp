#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	} 
	else{
		cout<<"0000";
		return 0;
	}
	char p1,p2;
	p1=s1.back();
	p2=s2.back();
	s1.pop_back();
	s2.pop_back();
	if(s1==s2){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(((p1=='A'||p1=='B'||p1=='C')&&(p2=='A'||p2=='B'||p2=='C'))||((p1=='D'||p1=='F')&&(p2=='D'||p2=='F'))){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if((p1=='A'&&p2=='B')||(p1=='B'&&(p2=='A'||p2=='C'))||(p1=='C'&&p2=='B')||(p1=='D'&&p2=='F')||(p1=='F'&&p2=='D')){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
