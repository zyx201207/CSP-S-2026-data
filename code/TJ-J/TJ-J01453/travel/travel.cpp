#include<bits/stdc++.h>
using namespace std;
int main(){
	// zyr zcr zsb zcg ztr zlx zlx zdd zdg zcd ztg zyr zzz
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b;
	string as,bs;
	cin>>a>>as>>b>>bs;
	if(a==b){
		cout<<"1";
		
		if(as[0]==bs[0]&&as[1]==bs[1]){
			cout<<"1";
			
			bool ap=(as.back()=='A'||as.back()=='B'||as.back()=='C');
			bool bp=(bs.back()=='A'||bs.back()=='B'||bs.back()=='C');
			if(ap==bp){
				cout<<"1";
				
				char ab=as.back(),bb=bs.back();
				if(ab>bb) swap(ab,bb);
				if((ab=='A'&&bb=='B')||(ab=='B'&&bb=='C')||(ab=='D'&&bb=='F')){
					cout<<"1"; 
				}else{
					cout<<"0"; 
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000"; 
		}
	}else{
		cout<<"0000"; 
	}
	return 0;
} 
