#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string ca,sa,cb,sb;
	cin>>ca>>sa>>cb>>sb;
	int judge1,judge2,judge3,judge4;
	if(ca==cb)	judge1=1;
	else judge1=0;
	if(judge1==1){
		if(sa.substr(0,2)==sb.substr(0,2))
			judge2=1;
		else
			judge2=0;
	}
	else judge2=0;
	if(judge1==1&&judge2==1){
		if((sa[2]>='A'&&sa[2]<='C'&&sb[2]>='A'&&sb[2]<='C')||(sa[2]>='D'&&sa[2]<='E'&&sb[2]>='D'&&sb[2]<='E'))
			judge3=1;
		else judge3=0;
	}
	else judge3=0;
	if(judge1==1&&judge2==1&&judge3==1){
		if(sa[2]-sb[2]==1||sa[2]-sb[2]==-1)
			judge4=1;
		else judge4=0;
	}
	else judge4=0;
	cout<<judge1<<judge2<<judge3<<judge4;
return 0;
}
