#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		cout << "0000";
		return 0;
	}
	int w1,w2;
	w1=(s1[0]-'0')*10+s1[1]-'0';
	w2=(s2[0]-'0')*10+s2[1]-'0';
	if(w1!=w2){
		cout << "1000";
		return 0;
	}
	if(s1[2]>='D'){
		if(s2[2]>='D') cout << "1111";
		else cout << "1100";
		return 0;
	}
	if(s2[2]>='D') cout << "1100";
	else if((s1[2]=='A' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='A')) cout << "1110";
	else cout << "1111";
	return 0;
}
