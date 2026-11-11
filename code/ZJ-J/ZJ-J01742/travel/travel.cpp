#include<bits/stdc++.h>
using namespace std;

bool memjfs;
long long crR,stR,crX,stX;
char slR,slX;
string cr,sr,cx,sx;
bool jug(){
	if(slR<='C'&&slX<='C'){
		return abs((long long )slR-slX)==1;
	} else {
		return 1;
	}
}
bool memjff;

int main(){
//	printf("%.8lfMB\n",(&memjff-&memjfs)/1024.0/1024.0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>cr>>sr>>cx>>sx;
	
	crR=((cr[0]^48)<<3)+((cr[0]^48)<<1)+(cr[1]^48);
	stR=((sr[0]^48)<<3)+((sr[0]^48)<<1)+(sr[1]^48);
	crX=((cx[0]^48)<<3)+((cx[0]^48)<<1)+(cx[1]^48);
	stX=((sx[0]^48)<<3)+((sx[0]^48)<<1)+(sx[1]^48);
	slR=sr[2];
	slX=sx[2];
	
	if(crR==crX){
		if(stR==stX){
			if(slR<='C'&&slX<='C'||slR>='D'&&slX>='D'){
				if(jug()){
					cout<<"1111";
				} else {
					cout<<"1110";
				}
			} else {
				cout<<"1100";
			}
		} else {
			cout<<"1000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}
