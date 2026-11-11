#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[1000];
int main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		cout << "0000";
		return 0;
	}
	if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
		cout << "1000";
		return 0;
	}
	x[(int)'A'] = 1;
	x[(int)'B'] = 2;
	x[(int)'C'] = 3;
	x[(int)'D'] = 4;
	x[(int)'F'] = 5;
	int a = x[s1[2]],b = x[s2[2]];
	if(a>b){
		int c = a;
		a = b;
		b = c;
	}
	if(a<=3&&b>=4){
		cout << "1100";
		return 0;
	}
	if(b-a==1) cout << "1111";
	else cout << "1110";
	return 0;
}
//rp++
