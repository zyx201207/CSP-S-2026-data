#include<bits/stdc++.h>
using namespace std;
string w1,w2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int q1,q2;
	cin>>q1>>w1>>q2>>w2;
	if(q1==q2){
		if(w1[0]==w2[0]&&w1[1]==w2[1]){
			if(((w1[2]<=67)&&(w2[2]<=67))||((w1[2]>67)&&(w2[2]>67))){
				if((w1[2]=='A'||w1[2]=='C')&&(w2[2]=='A'||w2[2]=='C')){
					cout<<"1110";
				}else{
					cout<<"1111";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
