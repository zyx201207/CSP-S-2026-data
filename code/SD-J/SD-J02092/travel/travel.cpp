#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	int xi1=0,xi2=0;
	xi1=10*int(a[0]-'0')+int(a[1]-'0');
	xi2=10*int(c[0]-'0')+int(c[1]-'0');
	//cout << xi1 << xi2;
	if(xi1!=xi2){
		cout << 0 << 0<< 0 << 0;
		return 0;
	}else cout << 1;
	int s1=10*int(b[0]-'0')+int(b[1]-'0');
	int s2=10*int(d[0]-'0')+int(d[1]-'0');
	if(s1!=s2){
		cout << 0 << 0 << 0;
		return 0;
	}else cout << 1;
	char ss1=b[2],ss2=d[2];
	if((ss1>='A'&&ss2<='C')||(ss1>='D'&&ss2<='F')){
		cout << 1;
	}else{
		cout << 0 << 0;
		return 0;
	}
	if(ss1>='D'&&ss2<='F'){
		cout << 1;
	}else if(ss1+1==ss2||ss2+1==ss1){
		
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
