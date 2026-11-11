#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string que1,que2,que3,que4;
	cin>>que1>>que2>>que3>>que4;
	cout<<que1<<que2<<que3<<que4;
	if(que1==que3){
		cout<<1;
		if(que2[0]==que4[0]&&que2[1]==que4[1]){
			cout<<1;
			if(que2[2]=='A'){
				if(que4[2]=='B')cout<<11;
				else if(que4[2]=='C')cout<<10;
				else cout<<0<<0;
			}
			if(que2[2]=='B'){
				if(que4[2]=='A')cout<<11;
				else if(que4[2]=='C')cout<<11;
				else cout<<0<<0;
			}
			if(que2[2]=='C'){
				if(que4[2]=='A')cout<<10;
				else if(que4[2]=='B')cout<<11;
				else cout<<0<<0;
			}
			if(que2[2]=='D'){
				if(que4[2]=='F')cout<<11;
				else cout<<0<<0;
			}
			if(que2[2]=='F'){
				if(que4[2]=='D')cout<<11;
				else cout<<0<<0;
			}
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
