#include <bits/stdc++.h>
#define pii pair<int,int>
#define int long long
#define endl '\n'
using namespace std;

char yr,yx;
string cr,sr,cx,sx,lr,lx;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cr>>sr>>cx>>sx;
	if (cr==cx) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	lr = sr[0]+sr[1];
	lx = sx[0]+sx[1];
	yr = sr[2];
	yx = sx[2];
	if (lr==lx) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if (yr>yx) swap(yr,yx);//yr<yx
	if (yx<'D'||'C'<yr) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if ((yx-yr==1)&&(yr!='C')) cout<<"1";
	else cout<<"0";
	return 0;
}
