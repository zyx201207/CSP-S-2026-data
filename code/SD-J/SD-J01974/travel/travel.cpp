#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sa,ssa,sb,ssb;
	cin>>sa>>ssa>>sb>>ssb;
	if(sa==sb){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	string cnta="",cntb="";
	for(int i=0;i<2;i++){
		cnta+=ssa[i];
		cntb+=ssb[i];
	}
	if(cnta==cntb){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	char aa=ssa[2];
	char bb=ssb[2];
	int a=int(aa-'A');
	int b=int(bb-'A');
	if((a<=2 and b<=2) or (a>2 and b>2)){
		cout<<1;
		if(abs(a-b)==1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<"00";
		return 0;
	}
	return 0;
}
