#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		char a1=s1[0],a2=s1[1];
		char b1=s2[0],b2=s2[1];
		int x=s1[2]-'A',y=s2[2]-'A';
		if(a1!=b1||a2!=b2){
			cout<<1000;
		}
		else{
			if(x>y)swap(x,y);
			if((x==0&&y==1)||(x==1&&y==2)||(x==3&&y==5)){
				cout<<1111;
			}
			else if(x==0&&y==2){
				cout<<1110;
			}
			else{
				cout<<1100;
			}
		}
	}
	return 0;
}
