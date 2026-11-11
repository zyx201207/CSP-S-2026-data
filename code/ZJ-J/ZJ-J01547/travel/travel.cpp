#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin >>a>>b>>c>>d;
	if(a==c){
		cout <<1;
	}else cout <<0;
	if(a==c&&b[0]+b[1]==d[0]+d[1]){
		cout <<1;
	}else cout <<0;
	if(a==c&&b[0]+b[1]==d[0]+d[1]&&!((b[2]=='D'||b[2]=='F')^(d[2]=='D'||d[2]=='F'))){
		cout <<1;
	}else cout <<0;
	if(a==c&&b[0]+b[1]==d[0]+d[1]&&!((b[2]=='D'||b[2]=='F')^(d[2]=='D'||d[2]=='F'))){
		char B=b[2],D=d[2];
		if(B>D){
			swap(B,D);
		}
		if((B=='A'&&D=='B')||(B=='B'&&D=='C')||(B=='D'&&D=='F')){
			cout <<1;
		}else cout <<0;
	}else cout <<0;
	return 0;
}
