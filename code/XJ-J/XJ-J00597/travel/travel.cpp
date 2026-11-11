#include<iostream>
#include<string.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ac,bc;
	cin>>ac;
	string as,bs;
	cin>>as;
	cin>>bc;
	cin>>bs;
	string tcx="0000";
	if(ac==bc) tcx[0]='1';
	if((as[0]-'0')*10+(as[1]-'0')==(bs[0]-'0')*10+(bs[1]-'0')&&tcx[0]=='1') tcx[1]='1';
	if(tcx[1]=='1'&&tcx[0]=='1'&&as[2]<='C'&&as[2]>='A'&&bs[2]<='C'&&bs[2]>='A') tcx[2]='1';
	else if(tcx[1]=='1'&&tcx[0]=='1'&&as[2]<='F'&&as[2]>='D'&&bs[2]<='F'&&bs[2]>='D') tcx[2]='1';
	if(tcx[2]=='1'){
		if(as[2]-bs[2]==1||as[2]-bs[2]==-1) tcx[3]='1';
	}
	cout<<tcx;
	return 0;
}