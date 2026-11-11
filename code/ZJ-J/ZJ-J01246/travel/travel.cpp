#include<bits/stdc++.h>
using namespace std;
string aq,bq,ap,bp;
int in_num(char a){
	return int(a-'0');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>aq>>ap>>bq>>bp;
	if(aq==bq){
		cout<<"1";
		int anum=in_num(ap[0])*10+in_num(ap[1]),bnum=in_num(bp[0])*10+in_num(bp[1]);
		char aw=ap[2],bw=bp[2];
		if(anum==bnum){
			cout<<"1";
			if((aw=='D' and bw=='F') or (bw=='D' and aw=='F')){
				cout<<11;
				return 0;
			}
			if((aw<='C' and bw<='C')){
				cout<<1;
				if((aw=='A' and bw=='B') or (aw=='B' and bw=='C'))cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
