#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int x1,x2,y1,y2;
	char ch1,ch2;
	x1=(c1[0]-'0')*10+c1[1]-'0';
	x2=(c2[0]-'0')*10+c2[1]-'0';
	y1=(s1[0]-'0')*10+s1[1]-'0';
	y2=(s2[0]-'0')*10+s2[1]-'0';
	ch1=s1[2];
	ch2=s2[2];
	if(x1==x2){
		if(y1==y2){
			if((ch1=='D'&&ch2=='F')||(ch1=='F'&&ch2=='D')||(ch1!='D'&&ch1!='F'&&ch2!='D'&&ch2!='F')){
				if((ch1=='D'&&ch2=='F')||(ch1=='F'&&ch2=='D')||(ch1=='A'&&ch2=='B')||(ch1=='B'&&ch2=='A')||(ch1=='B'&&ch2=='C')||(ch1=='C'&&ch2=='B')){
					cout<<"1111"<<endl;
				}else{
					cout<<"1110"<<endl;
				}
			}else{
				cout<<"1100"<<endl;
			}
		}else{
			cout<<"1000"<<endl;
		}
	}else{
		cout<<"0000"<<endl;
	}
	return 0;
}
