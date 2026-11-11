#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    char cha[3],chb[3],sha[5],shb[5];
	for(int i=1;i<=2;i++){
        cin>>cha[i];	
	}
	for(int i=1;i<=3;i++){
        cin>>chb[i];	
	}
		for(int i=1;i<=2;i++){
        cin>>sha[i];	
	}
	for(int i=1;i<=3;i++){
        cin>>shb[i];	
	}
	if(cha[1]==sha[1]&&cha[2]==sha[2]) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(chb[1]==shb[1]&&chb[2]==shb[2]){
		cout<<1;
		if(chb[3]=='D'||chb[3]=='F'){
			if(shb[3]=='D'||shb[3]=='F'){
				cout<<1<<1;
			}
			else{
				cout<<"00";
			}
		}
		else if(chb[3]=='A'||chb[3]=='B'||chb[3]=='C'){
			if(shb[3]=='A'||shb[3]=='B'||shb[3]=='C'){
				cout<<1;
				if(chb[3]=='A'&&shb[3]=='B'){
					cout<<1;
				}
				else if(chb[3]=='B'){
					cout<<1;
				}
				else if(chb[3]=='C'&&shb[3]=='B'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
    }
	else cout<<"000";
	
	return 0;
} 
