#include<bits/stdc++.h>
using namespace std;
#define int long long
string c_1,s_1,c_2,s_2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1!=c_2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(s_1[0]!=s_2[0]||s_1[1]!=s_2[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	char a=s_1[2],b=s_2[2];
	if(a>b)swap(a,b);
	if(a<='C'&&b>'C'){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(a+1==b){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
} 
