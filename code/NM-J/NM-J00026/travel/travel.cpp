#include <bits/stdc++.h>
using namespace std;
string a,c;
char b[10],d[10],k[5]={'A','B','C','D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b+1 >> c >> d+1;
	if(a == c){
		cout << '1';
	}
	else{
		cout << "0000";
		return 0;
	}
	if((b[1] == d[1])&&(b[2] ==d[2])){
		cout << '1';
		int flag=0,flag1=0;
		for(int i=3;i<5;i++){
			if(b[3] == k[i]) flag=1;
			if(d[3] == k[i]) flag1=1;
		}
		if(flag == flag1){
			cout << '1';
			if(flag && flag1)cout << '1';
			else if(b[3]=='C' && d[3]=='B' ||d[3]=='C' && b[3]=='B'){
				cout << '1';
			}
			else if(b[3]=='B' && d[3]=='A' || d[3]=='B' && b[3]=='A'){
				cout << '1';
			}
			else{
				cout << '0';
			}
		}
		else{
			cout << "00";
		}
	}
	else{
		cout << "000";
	}
	cout << endl;
	return 0;
}
