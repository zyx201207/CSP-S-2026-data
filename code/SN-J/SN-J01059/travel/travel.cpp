#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string idx,idy;
	for(int i=0;i<=1;i++){
		idx+=s1[i];
		idy+=s2[i];
	}
	char sx=s1[2],sy=s2[2];
	if(c1==c2){
		cout<<1;
		if(idx==idy){
			cout<<1;
			if(sx=='A'&&sy=='B'){
				cout<<"11";
			}else if(sx=='A'&&sy=='C'){
				cout<<"10"; 
			}else if(sx=='A'&&sy=='D'){
				cout<<"00"; 
			}else if(sx=='A'&&sy=='F'){
				cout<<"00"; 
			}else if(sx=='B'&&sy=='A'){
				cout<<"11"; 
			}else if(sx=='B'&&sy=='C'){
				cout<<"11"; 
			}else if(sx=='B'&&sy=='D'){
				cout<<"00"; 
			}else if(sx=='B'&&sy=='F'){
				cout<<"00"; 
			}else if(sx=='C'&&sy=='A'){
				cout<<"10"; 
			}else if(sx=='C'&&sy=='B'){
				cout<<"10"; 
			}else if(sx=='C'&&sy=='D'){
				cout<<"00";
			}else if(sx=='C'&&sy=='F'){
				cout<<"00"; 
			}else if(sx=='D'&&sy=='A'){
				cout<<"00"; 
			}else if(sx=='D'&&sy=='B'){
				cout<<"00"; 
			}else if(sx=='D'&&sy=='C'){
				cout<<"00";
			}else if(sx=='D'&&sy=='F'){
				cout<<"11"; 
			}else if(sx=='F'&&sy=='A'){
				cout<<"00"; 
			}else if(sx=='F'&&sy=='B'){
				cout<<"00"; 
			}else if(sx=='F'&&sy=='C'){
				cout<<"00"; 
			}else if(sx=='F'&&sy=='D'){
				cout<<"11"; 
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
