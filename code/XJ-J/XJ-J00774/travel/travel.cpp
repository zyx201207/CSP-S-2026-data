#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cxa,cxb;
	vector<char> zwa(3),zwb(3);
	cin>>cxa;
	for(int i=0;i<=2;++i)cin>>zwa[i];
	cin>>cxb;
	for(int i=0;i<=2;++i)cin>>zwb[i];
	if(cxa!=cxb){
		for(int i=1;i<=4;++i)cout<<0;
		return 0;
	}
	else cout<<1;
	if(zwa[0]==zwb[0]&&zwa[1]==zwb[1])cout<<1;
	else{
		for(int i=1;i<=3;++i)cout<<0;
		return 0;
	} 
	if(('A'<=zwa[2]&&zwa[2]<='C')&&('A'<=zwb[2]&&zwb[2]<='C'))cout<<1;
	else if((zwa[2]=='D'&&zwb[2]=='E')||(zwa[2]=='E'&&zwb[2]=='D')){
		cout<<11;
		return 0;
	}
	else{
		for(int i=1;i<=2;++i)cout<<0;
		return 0;
	} 
	if(zwa[2]=='B'||zwb[2]=='B'){
		if(zwa[2]=='A'||zwa[2]=='C'||zwb[2]=='A'||zwb[2]=='C')
			cout<<1;
	}   
	else cout<<0;
	return 0;
	}