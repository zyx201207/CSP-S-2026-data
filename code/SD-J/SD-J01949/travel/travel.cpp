#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string R0,Rid,X0,Xid;
	cin>>R0>>Rid[0]>>Rid[1]>>Rid[2]>>X0>>Xid[0]>>Xid[1]>>Xid[2];
	if(R0==X0){
		cout<<"1";
		if(Rid[0]==Xid[0]&&Rid[1]==Xid[1]){
			cout<<"1";
			if(Rid[2]=='D'&&Xid[2]=='F'||Rid[2]=='F'&&Xid[2]=='D'){
				cout<<"11";
			}else if(Rid[2]=='A'&&Xid[2]=='B'||Rid[2]=='B'&&Xid[2]=='A'||Rid[2]=='B'&&Xid[2]=='C'||Rid[2]=='C'&&Xid[2]=='B'){
				cout<<"11";
			}else if(Rid[2]=='A'&&Xid[2]=='C'||Rid[2]=='C'&&Xid[2]=='A'){
				cout<<"10";
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
