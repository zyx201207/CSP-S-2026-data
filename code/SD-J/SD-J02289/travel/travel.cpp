#include<bits/stdc++.h>
using namespace std;
bool sr=0,sx=0,sc=0,sl=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		sx=1;
	}
	int row1=0,row2=0;
	for(int i=0;i<3;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			row1=row1*10+(s1[i]-'0');
		}
		if(s2[i]>='0'&&s2[i]<='9'){
			row2=row2*10+(s2[i]-'0');
		}
	}
	if(sx&&(row1==row2)){
		sr=1;
	}
	int seat1,seat2;
	seat1=s1[2]-'A'+1;
	seat2=s2[2]-'A'+1;
	if(sr&&(seat1!=seat2&&((seat1<=3&&seat2<=3)||(seat1>=4&&seat2>=4)))){
		sc=1;
	}
	int c=max(seat1,seat2)-min(seat1,seat2);
	if(sc&&c==1){
		sl=1;
	}
	if(sx){
		cout<<1;
	}else{
		cout<<0;
	}
	if(sr){
		cout<<1;
	}else{
		cout<<0;
	}
	if(sc){
		cout<<1;
	}else{
		cout<<0;
	}
	if(sl){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
