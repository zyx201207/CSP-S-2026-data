#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
string s1,s2;
bool check(char x,char y){
	if(x=='A' || x=='B' || x=='C'){
		return y=='A' || y=='B' || y=='C';
	}else{
		return y=='E' || y=='F';
	}
}
bool check2(char x,char y){
	return abs(x-y)==1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s1>>m>>s2;
	if(n!=m){
		cout<<"0000";
		return 0;
	}else if(s1[0] != s2[0] || s1[1] != s2[1]){
		cout<<"1000";
	}else{
		if(check(s1[2],s2[2])){
			if(check2(s1[2],s2[2])){
				cout<<"1111";
			}else{
				cout<<"1110";
			}
		}else{
			cout<<"1100";
		}
	}
	return 0;
} 
