#include <bits/stdc++.h>
using namespace std;
string a,b,c,d,ans="0000";
int f=11;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[0]='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			ans[1]='1';
			if(('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C')||('D'<=b[2]&&b[2]<='E'&&'D'<=d[2]&&d[2]<='E')){
				ans[2]='1';
				if(b[2]=='A'&&d[2]=='C')f=0;
				else if(d[2]=='A'&&b[2]=='C')f=0;
				if(f!=0)ans[3]='1';
			}
		}
	}
	cout<<ans;
	return 0;
}
