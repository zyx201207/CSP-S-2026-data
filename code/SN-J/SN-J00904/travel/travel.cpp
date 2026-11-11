#include<bits/stdc++.h>
using namespace std;

string rc,rs,xc,xs;

int main(){
	freopen("travel.in","t",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc!=xc){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	int cut=0,ans=0;
	for(int i=0;i<3;i++){
		if(i<2){
			if(rs[i]==xs[i]){
				cut++;	
			}
		}
		if(i==2){
			if(cut!=2){
				cout<<"000";
				return 0;
			}
			if(rs[i]>='A'&&rs[i]<='C'&&xs[i]>='A'&&xs[i]<='C'){
				cout<<"11";
				if(rs[i]=='B'||xs[i]=='B'){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else if(rs[i]<='F'&&rs[i]>='D'&&xs[i]>='D'&&xs[i]<='F'){
				    cout<<"111";
				}else{
					cout<<"100";
					return 0;
				}
		}
	}
	return 0;
}
