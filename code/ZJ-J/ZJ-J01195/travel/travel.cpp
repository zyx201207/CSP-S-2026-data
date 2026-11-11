#include<bits/stdc++.h>
using namespace std;
#define int long long

string cc1,ss1,cc2,ss2;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cc1 >> ss1 >> cc2 >> ss2;
	if(cc1!=cc2){
		cout << "0000";
		return 0;
	}
	if(ss1[0]!=ss2[0] || ss1[1]!=ss2[1]){
		cout << "1000";
		return 0;
	}
	if((ss1[2]>='D')!=(ss2[2]>='D')){
		cout << "1100";
		return 0;
	}
	if(abs(ss1[2]-ss2[2])!=1){
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}

