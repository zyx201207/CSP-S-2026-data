#include<bits/stdc++.h>
using namespace std;
long long num,a[500005],sum,sra,srb,txa,txb;
int n;
char b[500005],cra,crb;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]; 
	}
	txa=1;
	txb=n;
	sra=a[1];
	srb=a[n];
	cra=b[1];
	crb=b[n];
	while(txb>txa){
		if(cra==crb){
			if(sra>srb){
				sra-=srb;
				txb--;
				srb=a[txb];
				crb=b[txb];
			}
			else if(sra==srb){
				txa++;
				txb--;
				sra=a[txa];
				cra=b[txa];
				srb=a[txb];
				crb=b[txb];
			}
			else{
				srb-=sra;
				txa++;
				sra=a[txa];
				cra=b[txa];
			}
		}
		else{
			if(sra>srb){
				num+=srb;
				sra-=srb;
				txb--;
				srb=a[txb];
				crb=b[txb];
			}
			else if(sra==srb){
				num+=sra;
				txa++;
				txb--;
				sra=a[txa];
				cra=b[txa];
				srb=a[txb];
				crb=b[txb];
			}
			else{
				num+=sra;
				srb-=sra;
				txa++;
				sra=a[txa];
				cra=b[txa];
			}
		}
	}
	cout<<num;
	return 0;
}
