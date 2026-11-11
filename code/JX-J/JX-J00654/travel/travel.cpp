#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
bool ans1,ans2,ans3,ans4;
bool check(char aa,char bb){
	char a = aa,b = bb;
	if(a > b) swap(a,b);
	if(b == 'F'){
		if(a == 'D') return 1;
		return 0;
	}
	if(a == 'D') return 0;
	return (b - a == 1);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> ca >> sa >> cb >> sb;
	ans1 = (ca == cb);
	ans2 = (ans1 && sa[0] == sb[0] && sa[1] == sb[1]);
	ans3 = (ans2 && ( (sa[2] <= 'C' && sb[2] <= 'C') || (sa[2] > 'C' && sb[2] > 'C') ) );
	ans4 = (ans3 && check(sa[2],sb[2]));
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
}
//RP ++
//Luogu @zzhengxi
