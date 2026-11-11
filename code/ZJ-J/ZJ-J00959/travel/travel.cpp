#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int w1=0;
	int w2=0;
	int w3=0;
	int w4=0;
	string z,k;	
	char a,b,c,d;
	char a1,a2,a3,b1,b2,b3;
	cin>> a>>c>>a1 >>a2>>a3 >>b>>d >>b1 >>b2>>b3;
	z+=a3;
	k+=b3;
	if(a==b&&c==d){
		w1=1;
		if(a1==b1&&a2==b2){
			w2=1;		
			if(z=="A"&&k=="A"||z=="A"&&k=="B"||z=="A"&&k=="C"||z=="B"&&k=="A"||z=="B"&&k=="B"||z=="B"&&k=="C"||z=="C"&&k=="A"||z=="C"&&k=="B"||z=="C"&&k=="A"||z=="E"&&k=="F"||z=="F"&&k=="E"){
				w3=1;
				if((z==k&&(a2+10*a1-b2-10*b2==1||a2+10*a1-b2-10*b2==-1))||((z=="A"&&k=="A"||z=="A"&&k=="B"||z=="B"&&k=="A"||z=="B"&&k=="B"||z=="B"&&k=="C"||z=="C"&&k=="B"||z=="E"&&k=="F"||z=="F"&&k=="E")&&(a1==b1&&a2==b2))){
					w4=1; 
				}
			}			
		}	
		else
			if((z==k&&(a2+10*a1-b2-10*b2==1||a2+10*a1-b2-10*b2==-1))||((z=="A"&&k=="A"||z=="A"&&k=="B"||z=="B"&&k=="A"||z=="B"&&k=="B"||z=="B"&&k=="C"||z=="C"&&k=="B"||z=="E"&&k=="F"||z=="F"&&k=="E")&&(a1==b1&&a2==b2))){
					w4=1; 
			}		
	}			
	cout<<w1<<w2<<w3<<w4;
	return 0;
}
