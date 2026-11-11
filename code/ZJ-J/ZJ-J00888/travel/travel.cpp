#include<bits/stdc++.h>
using namespace std;
#define _ long long
char a[30];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9]>>a[10];
	if(a[1]!=a[6]||a[2]!=a[7]){
		cout<<"0000";
		return 0;
	}
	if(a[3]!=a[8]||a[4]!=a[9]){
		cout<<"1000";
		return 0;
	}
	if((a[5]<='C')^(a[10]<='C')){
		cout<<"1100";
		return 0;
	}
	if((a[5]=='A'&&a[10]=='C')||(a[5]=='C'&&a[10]=='A')){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}