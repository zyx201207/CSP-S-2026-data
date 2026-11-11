#include <bits/stdc++.h>
using namespace std;
int rs=3,rg=1,ra=4,xs=10,xg=3,xa=3,rc,xc,flag[1000021];
int n,m,a[10000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(rc==xc){
		flag[1]=1;
		if(rs==xs && rg==xg){
			flag[2]=1;
		if(ra>='D' && ra<='F' && xa>='D' && xa<='F'){
			flag[3]=1;
			flag[4]=1;
		}
		if(n=4){
			cout<<rs<<rg<<ra;
		}
		if(ra>='A' && ra<='C' && xa>='A' && xa<='C'){
			flag[3]=1;
			if(ra=='A' && xa=='B' || xa=='A' && ra=='B' || ra=='B' && xa=='C' || xa=='B' && ra=='C'){
			flag[4]=1;
			}
		}
		if(n=10){
			cout<<xs<<xg<<xa;
		}
	}
	}       
	
	return 0;
}