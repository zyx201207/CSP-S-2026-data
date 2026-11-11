#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	char b[3],d[3];
	cin >> a >> c;
	for(int i = 1;i <= 4;i++){
		cin >> b[i] >> d[i];
	}
	if(a==c){
		cout << "1";
		if(b[1]+b[2]==d[1]+d[2]){
			cout << "111";	
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
	
}
