#include<bits/stdc++.h>
#define int long long
using namespace std;
string cx1,cx2,wz1,wz2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>wz1>>cx2>>wz2;
	if(cx1==cx2){
		cout<<1;
		if(wz1[0]==wz2[0]&&wz1[1]==wz2[1]){
			cout<<1;
			if(wz1[2]=='A'&&wz2[2]=='B'){
				cout<<1<<1;	
			}
			else if(wz1[2]=='A'&&wz2[2]=='C'){
				cout<<1<<0;	
			}
			else if(wz1[2]=='B'&&wz2[2]=='A'){
				cout<<1<<1;	
			}
			else if(wz1[2]=='B'&&wz2[2]=='C'){
				cout<<1<<1;	
			}
			else if(wz1[2]=='C'&&wz2[2]=='A'){
				cout<<1<<0;	
			}
			else if(wz1[2]=='C'&&wz2[2]=='B'){
				cout<<1<<1;	
			}
			else if(wz1[2]=='D'&&wz2[2]=='F'){
				cout<<1<<1;	
			}
			else if(wz1[2]=='F'&&wz2[2]=='D'){
				cout<<1<<1;	
			}
			else{
				cout<<0<<0;
			}
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
