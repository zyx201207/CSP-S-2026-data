#include<bits/stdc++.h>
using namespace std;
char a1[3],b1[4],a2[3],b2[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1[1]>>a1[2]>>b1[1]>>b1[2]>>b1[3];
	cin>>a2[1]>>a2[2]>>b2[1]>>b2[2]>>b2[3];
	if(a1[1]==a2[1]&&a1[2]==a2[2]){
		cout<<1;
		if(b1[1]==b2[1]&&b1[2]==b2[2]){
			cout<<1;
			if((b1[3]=='F' ||b1[3]=='D')&&(b2[3]=='F' ||b2[3]=='D')){
				cout<<1<<1;
			}else if((b1[3]=='A' ||b1[3]=='B'||b1[3]=='C')&&(b2[3]=='A' ||b2[3]=='B'||b2[3]=='C')){
				cout<<1;
				if(b1[3]==b2[3]-1 ||b1[3]==b2[3]+1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
