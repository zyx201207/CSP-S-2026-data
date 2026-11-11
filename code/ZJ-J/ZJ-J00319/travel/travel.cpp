#include<bits/stdc++.h>
using namespace std;
int cr,cx;
string sr,sx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx){cout<<"0000";return 0;}
	if(sr[0]!=sx[0]||sr[1]!=sx[1]){cout<<"1000";return 0;}
	bool wr=(sr[2]=='D'||sr[2]=='F'),wx=(sx[2]=='D'||sx[2]=='F');
	if(wr!=wx){cout<<"1100";return 0;}
	if(abs(sr[2]-sx[2])!=1){cout<<"1110";return 0;}
	cout<<"1111";
	return 0;
}