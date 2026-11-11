#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1!=x1){
		for(int i=0;i<4;i++){
			cout<<0;
		}
		return 0;
	}
	cout<<1;
	if(r2[0]==x2[0]&&r2[1]==x2[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	int r3=r2[2]-'A',x3=x2[2]-'A';
	int x=max(r3,x3),n=min(r3,x3);
	if((r3+x3)/2<=1||(r3+x3)/2==4){
		cout<<1;
		if(max(r3,x3)-min(r3,x3)==1){
			cout<<1;
		}
		else{
			if(x==5&&n==3){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	}
	else{
		cout<<0<<0;
	}
	return 0;
}
