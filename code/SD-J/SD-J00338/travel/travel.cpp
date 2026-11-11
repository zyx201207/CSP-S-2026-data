#include<bits/stdc++.h>
using namespace std;
int x,y;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>x>>a>>y>>b;
	if(x!=y){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if((a[0]*10+a[1])!=(b[0]*10+b[1])){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((a[2]<='C'&&b[2]>='D')||(a[2]>='D'&&b[2]<='C')){
		cout<<"00";
		return 0;
	}
	cout<<'1';
	if(abs(a[2]-b[2])==1){
		cout<<'1';
	}
	else cout<<'0';
	return 0;
}
