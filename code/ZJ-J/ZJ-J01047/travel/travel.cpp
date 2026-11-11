#include<bits/stdc++.h>
using namespace std;
string co, so, ct, st; 
bool fl[5];
int main(){
	for(int i=0;i<5;i++){
		fl[i]=false;
	}
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>co>>so>>ct>>st;
	if(co==ct){
		fl[0]=true;
		if(so[0]==st[0]&&so[1]==st[1]){
			fl[1]=true;
			if((so[2]>='A'&&so[2]<='C'&&st[2]>='A'&&st[2]<='C')||(so[2]>='D'&&so[2]<='F'&&st[2]>='D'&&st[2]<='F')){
				fl[2]=true;
				char a=so[2];
				char b=st[2];
				if(a=='F'){
					a='E';
				}
				if(b=='F'){
					b='E';
				}
				if(int(b-a)==-1||int(b-a)==1){
					fl[3]=true;
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<fl[i];
	}
	return 0;	
}