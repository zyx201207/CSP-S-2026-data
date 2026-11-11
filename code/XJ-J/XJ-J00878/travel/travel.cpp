#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx,ans;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){		
		ans.push_back('1');
		if(sr[0]==sx[0] && sr[1]==sx[1]){
			ans.push_back('1');
			if((sr[2]=='A' || sr[2]=='B')|| sr[2]=='C'){
				if(sx[2]=='D' || sx[2]=='E'){
					for(int i=1;i<=2;i++){
					ans.push_back('0');
					}
				}
			else{
					ans.push_back('1');
					int seatr=sr[2]-'0';
					int seatx=sx[2]-'0';
					if(seatr-seatx==1 || seatx-seatr==1){
						ans.push_back('1');
					}else{
						ans.push_back('0');
					}
				}
		}
			if(sr[2]=='D' || sr[2]=='E'){
				if((sx[2]=='A' || sx[2]=='B')|| sx[2]=='C'){
					for(int i=1;i<=2;i++){
					ans.push_back('0');
					}
				}
				else{
					ans.push_back('1');
					int seatr=sr[2]-'0';
					int seatx=sx[2]-'0';
					if(seatr-seatx==1 || seatx-seatr==1){
						ans.push_back('1');
					}else{
						ans.push_back('0');
					}
				}
			}
		}else{
		for(int i=1;i<=3;i++){
			ans.push_back('0');
		}
		}
	}else{
		for(int i=1;i<=4;i++){
			ans.push_back('0');
		}
	}
	
	cout<<ans;
	
	return 0;
}

	

	

