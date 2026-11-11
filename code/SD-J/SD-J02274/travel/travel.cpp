#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string l1,l2,z1,z2;
	cin>>l1>>z1>>l2>>z2;
	int c1,c2,x1,x2,y1,y2;
	c1=(l1[0]-'0'+1)*10+(l1[1]-'0'+1);
	c2=(l2[0]-'0'+1)*10+(l2[1]-'0'+1);
	x1=(z1[0]-'0'+1)*10+(z1[1]-'0'+1);
	x2=(z2[0]-'0'+1)*10+(z2[1]-'0'+1);
	y1=(z1[2]-'A'+1);
	y2=(z2[2]-'A'+1);
	if(y1==6){
		y1--;
	}
	if(y2==6){
		y2--;
	}
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(x1==x2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(x1==x2&&(y1>=4&&y2>=4||y1<=3&&y2<=3)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(x1==x2&&((y1-1==y2||y2-1==y1)&&((y1>=4&&y2>=4)||(y1<=3&&y2<=3)))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
