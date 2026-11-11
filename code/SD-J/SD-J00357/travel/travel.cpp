#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using ll = long long;
string c1, s1, c2, s2; 
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(s1.substr(0, 2) != s2.substr(0, 2)){
		cout<<"000";
		return 0;
	}
	cout<<1;
	char S1 = s1[2], S2 = s2[2];
	if((int)S1 > (int)S2) swap(S1, S2);
	if('A' <= S1 && S2 <= 'C'){
		cout<<"1";
		if((int)S1+1 == S2){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else if(S1 == 'D' && S2 == 'F'){
		cout<<"11";
	}
	else{
		cout<<"00";
	}
	return 0;
} 
//fc.exe travel.out travel1.ans

