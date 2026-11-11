#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int sumr,sumx,wss,wx,sr,ss;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc[0]=='0') sumr=rc[1]-'0';
	else sumr=(rc[0]-'0')*10+rc[1]-'0';
	if(xc[0]=='0') sumx=xc[1]-'0';
	else sumx=(xc[0]-'0')*10+xc[1]-'0';
	if(sumr==sumx){
		cout<<1;
		if(rs[0]=='0') wss=rs[1]-'0';
		else wss=(rs[0]-'0')*10+rs[1]-'0';
		if(xs[0]=='0') wx=xs[1]-'0';
		else wx=(xs[0]-'0')*10+xs[1]-'0';
		if(wx==wss){
			cout<<1;
			sr=rs[2]-'A'+1;
			ss=xs[2]-'A'+1;
			if(sr<ss) swap(sr,ss);
			if(sr>=4&&ss>=4||sr<=3&&ss<=4){
				cout<<1;
				if(sr-ss==1) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
