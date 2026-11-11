#include<bits/stdc++.h>
using namespace std;
bool r,x;
int rc,xc;
string sr,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>rc;
	cin>>sr;
	cin>>xc;
	cin>>sx;
	if(sr[2]=='A'||sr[2]=='B'||sr[2]=='C')r=1;
	if(sx[2]=='A'||sx[2]=='B'||sx[2]=='C')x=1;
	if(rc==xc){
		cout<<1;
		if(sr[0]+sr[1]==sx[0]+sx[1]){
			cout<<1;
			if(r==x){
				cout<<1;
				if((r==1&&abs(sr[2]-sx[2])==1)||(r==0&&abs(sr[2]-sx[2])==2)){
					cout<<1;
				}else cout<<0;	
			}else cout<<"00";
		}else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
