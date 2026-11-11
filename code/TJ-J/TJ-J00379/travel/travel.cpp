#include <bits/stdc++.h>
using namespace std;
string sr1,sx1,sr2,sx2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sr1>>sr2>>sx1>>sx2;
	if(sr1==sx1) cout<<1;
	else cout<<0;
	if(sr2[0]+sr2[1]==sx2[0]+sx2[1]) cout<<1;
	else cout<<0;
	bool a=0;
	if((sr2[2]<='C'&&sx2[2]<='C')||(sr2[2]>='D'&&sx2[2]>='D')){
		a=1;
		cout<<1;
	}
	else cout<<0;
	if(a==1&&abs(sr2[2]-sx2[2])==1) cout<<1;
	else cout<<0;
	return 0;
}
