#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
string cr,sr,cx,sx;
int f=0;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	IO;
	cin>>cr>>sr>>cx>>sx;
	f=(cr==cx);
	cout<<f;
	f=(f&&sr[0]==sx[0]&&sr[1]==sx[1]);
	cout<<f;
	f=(f&&((sr[2]>='A'&&sr[2]<='C'&&sx[2]>='A'&&sx[2]<='C')||(sr[2]>='D'&&sr[2]<='F'&&sx[2]>='D'&&sx[2]<='F')));
	cout<<f;
	f=(f&&(abs((int)(sr[2]-sx[2]))==1));
	cout<<f<<'\n';
	
	return 0;
}

