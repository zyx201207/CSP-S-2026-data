#include<bits/stdc++.h>
//#define int long long
using namespace std;
string a,b,c,d; 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char m=b[2],n=d[2];
	if(m>n){
		swap(m,n);
	}
	if(m=='D'&&n=='F'){
		cout<<11;
	}else if(m=='A'&&n=='B'||m=='B'&&n=='C'){
		cout<<11;
	}else if(m=='A'&&n=='C'){
		cout<<10;
	}else{
		cout<<"00";
	}
	return 0;
}

