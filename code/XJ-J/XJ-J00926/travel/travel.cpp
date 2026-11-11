#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	int sum=a[0]-'0'+a[1]-'0';
	int cnt=c[0]-'0'+c[1]-'0';
	if(sum==cnt){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	int cut=b[0]-'0'+b[1]-'0';
	int ant=d[0]-'0'+d[1]-'0';
	if(cut==ant){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	if(((b[2]-'0'>=17 && b[2]-'0'<=19)&&(d[2]-'0'>=17 && d[2]-'0'<=19))||(b[2]=='D'&&d[2]=='F')){
		cout << 1;
	}else{
		cout << "00";
		return 0;
	}
	if(b[2]+1==d[2] || b[2]-1==d[2] || b[2]=='D'&&d[2]=='F'){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}