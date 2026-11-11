#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c3;
	string c2,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	char a=c2[2];
	char b=c4[2];
	char c=c2[0];
	char d=c4[0];
	char e=c2[1];
	char f=c4[1];
	if(c==d&&e==f){
		cout<<1;
	}else{
		cout<<"000"; 
		return 0;
	}
	int ans1=0,ans2=0;
	if(b>='A'&&b<='C'){
		ans1=1;
	}else{
		ans1=0;
	}
	if(a>='A'&&a<='C'){
		ans2=1;
	}else{
		ans2=0;
	}
	if(ans1==ans2){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(b-a==1||a-b==1){
		cout<<1;
	}else{
		cout<<"0"; 
	}
	return 0;
}

