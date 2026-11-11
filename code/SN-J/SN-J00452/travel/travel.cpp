#include<bits/stdc++.h>
using namespace std;
int conti,contj;
string sumi,sumj;
int vd1,vd2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>conti>>sumi>>contj>>sumj;
	if(sumi[2]=='A'||sumi[2]=='B'||sumi[2]=='C'){
		vd1++;
	}	
	if(sumj[2]=='A'||sumj[2]=='B'||sumj[2]=='C'){
		vd1++;
	}
	if(sumi[2]=='D'||sumi[2]=='E'){
		vd2++;
	}
	if(sumj[2]=='D'||sumj[2]=='E'){
		vd2++;
	}
	
	if(conti==contj){
		cout<<1;
		if(sumi[0]+sumi[1]==sumj[0]+sumj[1]){
			cout<<1;
			if(vd1==2||vd2==2){
				cout<<1;
				if(sumi[2]==sumj[2]+1||sumi[2]==sumj[2]-1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	
	return 0;
}
