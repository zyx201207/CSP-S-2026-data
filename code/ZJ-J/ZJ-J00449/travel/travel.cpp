#include<bits/stdc++.h>
#define int long long
using namespace std;
int r,x;
char s[10],ss[10];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>(s+1)>>x>>(ss+1);
	if(r!=x){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s[1]!=ss[1]||s[2]!=ss[2]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(!((s[3]<='C'&&ss[3]<='C')||(s[3]>'C'&&ss[3]>'C'))){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if((s[3]=='C'&&ss[3]=='A')||(s[3]=='A'&&ss[3]=='C')){
		cout<<0;
	}
	else cout<<1;
	return 0;
}
