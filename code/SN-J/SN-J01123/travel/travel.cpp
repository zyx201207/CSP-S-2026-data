#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2;
    string b1,b2;
	cin>>a1>>b1>>a2>>b2;
	int c[4]={0,0,0,0};
	if(a1==a2)
	{
		c[0]=1;
	}
	if(b1[0]==b2[0]&&b1[1]==b2[1]){
		c[1]=1;
	}
	if((b1[2]>='A'&&b1[2]<='C')&&(b2[2]>='A'&&b2[2]<='C')||(b1[2]=='D'||b1[2]=='F')&&(b2[2]=='D'||b2[2]=='F')){
		
			c[2]=1;
			if(b1[2]-b2[2]==1||b1[2]-b2[2]==-1){
				c[3]=1;
			}
		
	}
	for(int i=0;i<4;i++){
		cout<<c[i];
	}
	return 0;
} 
