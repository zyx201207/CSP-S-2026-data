#include<bits/stdc++.h> 
using namespace std;
int TX,TR,i,j,k,ans,s,a[6];
char SR[5],SX[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>TR>>SR>>TX>>SX;
	if(TX==TR)
{
	cout<<"1";
}
    else{
    	cout<<"0000";
    	return 0;
	}
	for(i=0;i<=1;i++){
		if(SR[i]!=SX[i]){
			cout<<"000";
			s=1;
			return 0;
		}
	}
	if(s==0){
		cout<<"1";
	}
	if((SR[2]-64<=3 and SX[2-64]<=3) or (SR[2]-64>3 and SX[2-64]>3)){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(SR[2]-64+1==SX[2]-64||SR[2]-64-1==SX[2]-64){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
    /*for(i=1;i<=2;i++){
        a[SR[2]-64]=1;
        a[SX[2]-64]=1;
	}
	for(i=1;i<=5;i++){
		if(a[i]=1){
			if(a[i+1]==1||a[i-1]==1){
				ans=1;
			}
		}
	}
	if((SR[2]-64<=3 and SX[2-64]<=3) or (SR[2]-64>3 and SX[2-64]>3)){
		cout<<"1";
	}
	if(ans==1){
		cout<<"1";
	}*/
}
