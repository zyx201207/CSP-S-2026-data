#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r1,x1,r22,x22;
	char r2,x2;
	cin>>r1>>r22>>r2>>x1>>x22>>x2;
	if(r1==x1){
		cout<<1;
		if(r22==x22){
			cout<<1;
			if(r2>='A'&&r2<='C'&&x2>='A'&&x2<='C'){
				cout<<1;
				if(r2+1==x2||r2-1==x2){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(r2=='D'&&x2=='F'||x2=='D'&&r2=='F'){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	return 0;
}