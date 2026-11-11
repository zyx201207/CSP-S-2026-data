#include<bits/stdc++.h>
using namespace std;
int a[256];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string rc,rz,xc,xz;
	cin>>rc>>rz>>xc>>xz;
	char rl=rz[2],xl=xz[2];
	a['A']=1;
	a['B']=2;
	a['C']=3;
	a['D']=4;
	a['F']=5;
	if(rc==xc){
		if(rz[0]==xz[0]&&rz[1]==xz[1]){
			if((a[rl]<=3&&a[xl]<=3)||(a[rl]>3&&a[xl]>3)){
				if(abs(a[rl]-a[xl])==2){
					cout<<"1110";
				}else{
					cout<<"1111";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
