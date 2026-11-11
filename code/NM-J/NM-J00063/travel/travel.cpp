#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string sc;
	string pds1=s1.substr(0,2);
	string pds2=s2.substr(0,2);
	char xls1=s1[2];
	char xls2=s2[2];
	//判断是否在同一节车厢
	if(c1==c2){
		sc+='1';
		
		//判断是否在一排 
	     if(pds1==pds2){
	     	sc+='1';
	     	//判断是否在同一侧
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E')){
				sc+='1';
				//判断是否是相邻
			int pdxl=int(xls1)-int(xls2);
				if(pdxl==1||pdxl==-1){
					sc+='1';
					cout<<sc;
				}
				else{
					sc="1110";
					cout<<sc;
				}
			}
			else{
				sc="1100";
				cout<<sc;
			}
		 }
		 
		 else if(pds1!=pds2){
		 	sc="1000";
		 	cout<<sc;
		 }
	} 
	if(c1!=c2){
		sc="0000";
		cout<<sc;
	}
     return 0;
}
