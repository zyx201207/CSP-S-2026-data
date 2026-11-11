#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int N=1e5+10;
int a1,b1,a2,b2;
char c1,c2;
signed main(){ IOS;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	if(a1==a2){
		cout<<1;
		if(b1==b2){
			cout<<1;
			if(('A'<=c1&&c1<='C'&&'A'<=c2&&c2<='C')||('D'<=c1&&c1<='E'&&'D'<=c2&&c2<='E')){
				cout<<1;
				if(abs(c2-c1)==1) cout<<1;
				else cout<<0;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}