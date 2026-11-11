#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	} 
	else{
		string str1=s1.substr(0,2);
		string str2=s2.substr(0,2);
		if(str1!=str2){
			cout<<"1000";
			return 0;
		}
		char k1=s1[2];
		char k2=s2[2];
		if('A'<=k1&&k1<='C'&&'A'<=k2&&k2<='C'){
			if(abs(k1-k2)==1) cout<<"1111";
			else cout<<"1110";
		}
		else if('D'<=k1&&k1<='E'&&'D'<=k2&&k2<='E'){
			cout<<"1111";
		}
		else{
			cout<<"1100";
		}
	}
	return 0;
}

