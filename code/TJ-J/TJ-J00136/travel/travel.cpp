#include <bits/stdc++.h> 
using namespace std;
#define int long long
string a1,a2;
string b1,b2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]==b2[0] and a2[1]==b2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char A = a2[2];
	char B = b2[2]; 
	if(abs(A-B) <= 2 and A != 'D' and B!='D'){
		cout<<1;
	}else if(A == 'D' and B == 'F' or A == 'F' and B == 'D'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(A-B)== 1 and A != 'D' and B!='D'){
		cout<<1; 
	}else if(A == 'D' and B == 'F' or A == 'F' and B == 'D'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
