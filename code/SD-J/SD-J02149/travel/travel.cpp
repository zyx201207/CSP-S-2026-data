#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int INF=2147483647;
ll che1,che2;
string wei1,wei2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>che1>>wei1>>che2>>wei2;
	if(che1==che2)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if((wei1[0]*10+wei1[1])==(wei2[0]*10+wei2[1]))cout<<"1";
	else {
		cout<<"000";
		return 0;
	}if(wei1[2]<='C'&&wei2[2]<='C'){
		cout<<'1';
	}else if(wei1[2]<='F'&&wei2[2]<='F'&&wei1[2]>='D'&&wei2[2]>='D'){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(int(wei1[2]-wei2[2]))==1)cout<<"1";
	else cout<<"0";
	return 0;
}
//RP+=INF

