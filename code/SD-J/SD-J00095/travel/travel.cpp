#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string rroom,rseat,xroom,xseat;
bool _room_,_line_,_side_,_nxt_;
ll rline,xline;
char rside,xside;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rroom>>rseat>>xroom>>xseat;
	_room_=(rroom==xroom?1:0);
	if(!(_room_)){cout<<"0000";return 0;}
	rline=(rseat[0]-'0')*10+(rseat[1]-'0'),xline=(xseat[0]-'0')*10+(xseat[1]-'0');
	_line_=(rline==xline?1:0);
	if(!(_line_)){cout<<_room_<<"000";return 0;}
	rside=rseat[2],xside=xseat[2];
	if(rside=='A'&&xside=='B')_side_=1;
	else if(rside=='A'&&xside=='C')_side_=1;
	else if(rside=='B'&&xside=='C')_side_=1;
	else if(rside=='B'&&xside=='A')_side_=1;
	else if(rside=='C'&&xside=='A')_side_=1;
	else if(rside=='C'&&xside=='B')_side_=1;
	else if(rside=='D'&&xside=='F')_side_=1;
	else if(rside=='F'&&xside=='D')_side_=1;
	if(!(_side_)){cout<<_room_<<_line_<<"00";return 0;}
	if(rside=='A'&&xside=='B')_nxt_=1;
	else if(rside=='B'&&xside=='C')_nxt_=1;
	else if(rside=='B'&&xside=='A')_nxt_=1;
	else if(rside=='C'&&xside=='B')_nxt_=1;
	else if(rside=='D'&&xside=='F')_nxt_=1;
	else if(rside=='F'&&xside=='D')_nxt_=1;
	if(!(_nxt_)){cout<<_room_<<_line_<<_side_<<"0";return 0;}
	cout<<"1111";
	return 0;
}
