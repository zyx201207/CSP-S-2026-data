#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
string a,b,c,d;
int cx_R,cx_X,ph_R,ph_X;
char zw_R,zw_X;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	cx_R=(a[0]-'0')*10+(a[1]-'0');
	cx_X=(c[0]-'0')*10+(c[1]-'0');
	if(cx_R!=cx_X) {
		cout<<"0000";
		return 0;
	}
	ph_R=(b[0]-'0')*10+(b[1]-'0');
	ph_X=(d[0]-'0')*10+(d[1]-'0');
	if(ph_R!=ph_X) {
		cout<<"1000";
		return 0;
	}
	zw_R=b[2];
	zw_X=d[2];
	if((zw_R<='C'&&zw_X<='C')||(zw_R>='D'&&zw_X>='D')) {
		if(zw_R+1==zw_X||zw_X+1==zw_R) {
			cout<<"1111";
			return 0;
		} else {
			cout<<"1110";
			return 0;
		}
	}
	cout<<"1100";
	return 0;
}