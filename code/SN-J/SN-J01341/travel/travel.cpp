#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,a,c1,a1;
	cin >> c >> a >> c1 >> a1;
	if(c==c1){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	if(a[0]==a1[0]&&a[1]==a1[1]){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	if((a[2]<='C'&&a1[2]<='C')||(a[2]>='D'&&a1[2]>='D')){
		cout << 1;
	}else{
		cout << "00";
		return 0;
	}
	int sum=a[2]-'0',sum1=a1[2]-'0';
	if(abs(sum-sum1)==1){
		cout << 1;
	}else{
		cout << "0";
		return 0;
	}
	return 0;
}
