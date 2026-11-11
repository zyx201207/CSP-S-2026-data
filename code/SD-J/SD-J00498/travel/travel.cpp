#include<bits/stdc++.h>
using namespace std;
string r,rz,x,xz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> r >> rz >> x >> xz;
	if(r != x) cout << "0000";
	else if(rz[0] != xz[0] || rz[1] != xz[1]) cout << "1000";
	else if(rz[2] <= 'C' && xz[2] >='D'||rz[2] >= 'D' && xz[2] <='C') cout << "1100";
	else if(rz[2] - xz[2] == 1 || rz[2] - xz[2] == -1 || (rz[2] - xz[2] == 2 || rz[2] - xz[2] == -2) && (rz[2] == 'D'||rz[2]=='F')) cout << "1111";
	else cout << "1110";
	return 0;
} 
