#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long car1,car2;
	string sit1,sit2;
	cin>>car1>>sit1>>car2>>sit2;
	if(car1==car2){
		cout<<1;
		if(sit1[1]==sit2[1]&&sit1[0]==sit2[0]){
			cout<<1;
			if(sit1[2]=='D'&&sit2[2]=='F'||sit1[2]=='A'&&sit2[2]=='B'||sit1[2]=='A'&&sit2[2]=='C'||sit1[2]=='B'&&sit2[2]=='C'||sit2[2]=='D'&&sit1[2]=='F'||sit2[2]=='A'&&sit1[2]=='B'||sit2[2]=='A'&&sit1[2]=='C'||sit2[2]=='B'&&sit1[2]=='C'){
				cout<<1;
				if(sit1[2]=='D'&&sit2[2]=='F'||sit1[2]=='A'&&sit2[2]=='B'||sit1[2]=='B'&&sit2[2]=='C'||sit2[2]=='D'&&sit1[2]=='F'||sit2[2]=='A'&&sit1[2]=='B'||sit2[2]=='B'&&sit1[2]=='C'){
					cout<<1;
				}
				else{
					cout<<0;
				}
	}
			else {
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
