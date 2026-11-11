#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a,b;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>c>>b>>d;
	if(a!=b){
		cout<<"0000";
	}else if((c[0]-'0')*10+c[1]-'0'!=(d[0]-'0')*10+d[1]-'0'){
			cout<<"1000";
	}
	else if(((c[2]<'D')&&(d[2]>'C'))||((c[2]>'C')&&(d[2]<'D'))){
		cout<<"1100";
	}
	else if(abs(c[2]-d[2])!=1) {
		cout<<"1110";
	}
	else cout<<"1111";
	return 0;
}
