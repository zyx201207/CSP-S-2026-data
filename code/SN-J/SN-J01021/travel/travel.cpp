// SN-J01021 Ê¦´ó01¿¼³¡  ³Â¼ÎÏé 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,xs1,ys1,xs2,ys2;
int xf,yf,xs,ys;
string x[18]={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18"};
string y[5]={"A","B","C","D","F"};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		printf("0000");
		return 0;
	} 
	else{
		printf("1");
		xs1[0]=s1[0];
		xs1[1]=s1[1];
		xs2[0]=s2[0];
		xs2[1]=s2[1];
		ys1=s1[2];
		ys2=s2[2]; 
		for(int i=0;i<5;i++){
			if(y[i]==ys1) yf=i;
			else if(y[i]==ys2) ys=i;
		}
		for(int i=0;i<18;i++){
			if(x[i][0]==xs1[0]&&x[i][1]==xs1[1]) xf=i;
			else if(x[i][0]==xs2[0]&&x[i][1]==xs2[1]) xs=i;
		}
		if(xf==xs){
			printf("1");
			if(((yf==0||yf==1||yf==2)&&(ys==0||ys==1||ys==2))||((yf==3||yf==4)&&(ys==3||ys==4))) printf("1");
			else printf("0");
			if(abs(yf-ys)==1&&((yf==0||yf==1||yf==2)&&(ys==0||ys==1||ys==2))||((yf==3||yf==4)&&(ys==3||ys==4))) printf("1");
			else printf("0");
		}
		else printf("000");
	}
	return 0;
}
