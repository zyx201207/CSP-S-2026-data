#include<bits/stdc++.h>
using namespace std;

int che1,che2,zuopai1,zuopai2;
char yiwei,erwei,s[10];
map<char,bool>b;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++){
		scanf("%s",s+1);
		int ls=strlen(s+1);
		if(i==1||i==3){
			int che=0;
			for(int j=1;j<=ls;j++)
				che=che*10+s[j]-'0';
			if(i==1)
				che1=che;
			else
				che2=che;
		}else{
			int zuopai=0;
			for(int j=1;j<=ls-1;j++)
				zuopai=zuopai*10+s[j]-'0';
			if(i==2){
				zuopai1=zuopai;
				yiwei=s[ls];
			}else{
				zuopai2=zuopai;
				erwei=s[ls];
			}
		}
	}
	b[yiwei]=true;
	b[erwei]=true;
	if(che1==che2){
		cout<<"1";
		if(zuopai1==zuopai2){
			cout<<"1";
			bool flag=false;
			if((yiwei<='C'&&erwei<='C')||(erwei>='D'&&yiwei>='D'))
				flag=true;
			if(flag==true){
				cout<<"1";
				flag=false;
				if((b['A']==true&&b['B']==true)||(b['B']==true&&b['C']==true)||(b['D']==true&&b['F']==true))
					flag=true;
				if(flag)
					cout<<"1";
				else
					cout<<"0";
			}else
				cout<<"00";
		}else
			cout<<"000";
	}else
		cout<<"0000";
}