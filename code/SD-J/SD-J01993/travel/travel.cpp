#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	char a1,b1,c1,d1,e1;
	char a2,b2,c2,d2,e2;
	cin>>a1>>b1>>c1>>d1>>e1;
	cin>>a2>>b2>>c2>>d2>>e2;
	if(a1==a2&&b1==b2){
		cout<<"1";
		if(c1==c1&&d1==d2){
			cout<<"1";
			if(e1<='C'&&e1>='A'&&e2<='C'&&e2>='A'){
				cout<<"1";
				if(abs(e1-e2)==1) cout<<"1";
				else cout<<"0";
			}
			else if(e1>='D'&&e1<='E'&&e2>='D'&&e2<='E'){
				cout<<"1";
				if(abs(e1-e2)==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
