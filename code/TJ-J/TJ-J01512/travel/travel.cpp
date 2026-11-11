#include<bits/stdc++.h>
using namespace std;
int a,ax,b,bx;
char ac,bc;
char sa[8]={'D','F','A','B','B','C','A','C'},sb[8]={'F','D','B','A','C','B','C','A'};
int f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>ax>>ac>>b>>bx>>bc;
	if(a==b){
		cout<<1;
		if(ax==bx){
			cout<<1;
			for(int i=0;i<8;i++){
				if(sa[i]==ac&&sb[i]==bc){
					if(i>=6){
						cout<<"10";
					}
					else{
						cout<<"11";
					}
					f=1;
					break;
				}
			}
			if(!f){
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
} 
