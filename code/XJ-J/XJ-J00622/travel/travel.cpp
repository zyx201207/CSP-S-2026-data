#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1){
		cout<<0000;
		return 0;
	}
	if(b1==a1){
		cout<<1;

	}else{
		cout<<0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]&&b1==a1){
		cout<<1;
	}else{
		cout<<0;

	}
	int pd=0;
	if((   (a2[2]<='C'&&b2[2]<='C')||(a2[2]>='D'&&b2[2]>='D')   )&&a2[0]==b2[0]&&a2[1]==b2[1]&&b1==a1){
		cout<<1;
		pd=1;
	}else{
		cout<<0;
	}
	
	//pd
	int azw=(int(a2[0]-'0'))*10+int(a2[1]-'0');
	int bzw=(int(b2[0]-'0'))*10+int(b2[1]-'0');
	char al=a2[2],bl=b2[2];
	if(al=='F'){
		al='E';
	}
	if(bl=='F'){
		bl='E';
	}
	if(b1!=a1){
		cout<<0;
		return 0;
	}//cx    

	
	if(abs(bzw-azw)>=2){
		cout<<0;
		return 0;
	}//zwty
	if(pd==0){
		cout<<0;
		return 0;
	}//gd
 	if(al=='C'||al=='E'){
 		if(azw+1==bzw||azw-1==bzw||char(al-1)==bl){
 			cout<<1;
 			return 0;
		 }
	}//==c||==f
	if(al=='B'){
 		if(azw+1==bzw||azw-1==bzw||char(al-1)==bl||char(al+1)==bl){
 			cout<<1;
 			return 0;
		 }
	}//==B
	if(al=='A'||al=='D'){
 		if(azw+1==bzw||azw-1==bzw||char(al+1)==bl){
 			cout<<1;
 			return 0;
		 }
	}
	cout<<0;
	//==a||==d
	//666	youkeng 
	return 0;
} 
