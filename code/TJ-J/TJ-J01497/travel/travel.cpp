#include<bits/stdc++.h>
using namespace std;

bool ce(string s1,string s2){
	char c1=s1[0],c2=s2[0];
	if(c1=='A'||c1=='B'||c1=='C'){
		if(c2=='A'||c2=='B'||c2=='C'){
			return 1;
		}return 0;
	}
	if(c1=='D'||c1=='F'){
		if(c2=='D'||c2=='F'){
			return 1;
		}return 0;
	}
}
bool lin(string s1,string s2){
	char c1=s1[0],c2=s2[0];
	if(abs(int(c1)-int(c2))==1&&!(c1=='C'&&c2=='D')&&!(c1=='D'&&c2=='C')){
		return 1;
	}return 0;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string line1=s1.substr(0,2);
	s1.erase(0,2);
	string line2=s2.substr(0,2);
	s2.erase(0,2);
	if(c1!=c2){
		cout<<"0000";
	}else if(line1!=line2){
		cout<<"1000";
	}else if(!ce(s1,s2)){
		cout<<"1100";
	}else if(!lin(s1,s2)){
		cout<<"1110";
	}else cout<<"1111";
	
	return 0;
}
