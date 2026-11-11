#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string z1,z2,w1,w2,zc1,zc2;
	cin>>c1>>z1>>c2>>z2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	for(int i=0;i<3;i++){
		if(i==0){
			w1+=z1[i];
		}
		else if(i==1){
			w1+=z1[i];
		}
		else{
			zc1=z1[i];
		}
	}
	for(int i=0;i<3;i++){
		if(i==0){
			w2+=z2[i];
		}
		else if(i==1){
			w2+=z2[i];
		}
		else{
			zc2=z2[i];
		}
	}
	if(w1==w2&&c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	int f=0,q=0;
	if((zc1=="A"||zc1=="B"||zc1=="C")&&(zc2=="A"||zc2=="B"||zc2=="C")&&c1==c2&&w1==w2){
		cout<<"1";
		if((zc1=="A"&&zc2=="B")||(zc1=="B"&&zc2=="A")||(zc1=="B"&&zc2=="C")||(zc1=="C"&&zc2=="B")){
			q=1;
		}
		else{
			q=0;
		}
		f=1;
	}
	else if((zc1=="D"||zc1=="F")&&(zc2=="D"&&zc2=="F")&&c1==c2&&w1==w2){
		cout<<"1";
		f=2;
	}
	else{
		cout<<"0";
		f=0;
	}
	if(f==1&&c1==c2&&w1==w2&&q==1){
		cout<<"1";
	}
	else if(f==2&&c1==c2&&w1==w2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}

	return 0;
}
