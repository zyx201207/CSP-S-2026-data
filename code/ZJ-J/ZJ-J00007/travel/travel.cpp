#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if((b[2]>='D'&&d[2]<='C')||(b[2]<='C'&&d[2]>='D')){
				cout<<"00";
			}else{
				cout<<1;
				if((b[2]=='B'||d[2]=='B')||(b[2]>='D'&&d[2]>='D')){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

