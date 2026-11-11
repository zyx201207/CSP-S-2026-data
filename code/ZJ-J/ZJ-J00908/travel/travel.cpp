#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int a1=(s1[0]-48)*10,a2=(s2[0]-48)*10;
		int b1=(s1[1]-48),b2=(s2[1]-48);
		int c1=a1+b1,c2=a2+b2;
		if(c1==c2){
			cout<<1;
			int d1=(s1[2]-64),d2=(s2[2]-64);
			if((d1>=1&&d1<=3&&d2>=1&&d2<=3)||(d1>=4&&d1<=5&&d2>=4&&d2<=5)){
				cout<<1;
				if(abs(d1-d2)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
		
	}else{
		cout<<"0000";
	}
	return 0;
}
