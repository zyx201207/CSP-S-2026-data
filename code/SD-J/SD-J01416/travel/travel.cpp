#include<bits/stdc++.h>
#define ll long long
#define i128 __int128
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,n1,c2,n2; cin>>c1>>n1>>c2>>n2;
	bool flag0=0;
	if (c1==c2){
		cout<<"1";
		flag0=1;
	}
	if (!flag0){
		cout<<"0000";
		return 0;
	}
	bool flag1=0;
	if (n1[0]==n2[0]&&n1[1]==n2[1]){
		cout<<"1";
		flag1=1;
	}
	if (!flag1){
		cout<<"000";
		return 0;
	}
	bool flag2=0;
	if ((n1[2]<='C'&&n2[2]<='C')||(n1[2]>='D'&&n2[2]>='D')){
		cout<<"1";
		flag2=1;
	}
	if (!flag2){
		cout<<"00";
		return 0;
	}
	if (n1[2]<='C'&&n2[2]<='C'){
		if (abs(n1[2]-n2[2])==1) cout<<"1";
		else cout<<"0";
	}
	else if (n1[2]>='D'&&n2[2]>='D'){
		cout<<"1";
	} else cout<<"0";
	return 0;
}
