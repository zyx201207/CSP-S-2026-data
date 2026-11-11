#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	char a1[10],b1[10];
	bool c=0,c1=0,c2=0,c3=0;
	cin>>a;
	for(int i=1;i<=3;i++)cin>>a1[i];
	cin>>b;
	for(int i=1;i<=3;i++)cin>>b1[i];
	if(a==b){
		c=1;
		if(a1[1]==b1[1]&&a1[2]==b1[2]){
			c1=1;
			if((a1[3]<='C'&&b1[3]<='C')||(a1[3]>='D'&&b1[3]>='D')){
				c2=1;
				if(abs(a1[3]-b1[3])<=1)c3=1;
			}
		}
	}
	cout<<c<<c1<<c2<<c3;
	return 0;
}