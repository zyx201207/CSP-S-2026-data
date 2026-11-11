#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int cx1=(c1[0]-'0')*10+(c1[1]-'0'),cx2=(c2[0]-'0')*10+(c2[1]-'0');
	int line1=(s1[0]-'0')*10+(s1[1]-'0'),line2=(s2[0]-'0')*10+(s2[1]-'0');
	if(cx1==cx2){
		cout<<"1";
		if(line1==line2){
			cout<<"1";
			char se1=s1[2],se2=s2[2];
			if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))){
				cout<<"1";
				if(((se1=='B'&&(se2=='A'||se2=='C'))||(se2=='B'&&(se1=='A'||se1=='C')))||((se1=='D'&&se2=='F')||(se2=='D'&&se1=='F'))){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
}
