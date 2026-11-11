#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[13];
	for(int i=1;i<=10;i++){
		cin >> a[i];
	}
	if(a[1]==a[6]&&a[2]==a[7]){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	if(a[3]==a[8]&&a[4]==a[9]){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	if(a[5]<='C'&&a[10]<='C'){
		if((a[5]=='A'&&a[10]=='B')||(a[5]=='B'&&a[10]=='C')){
			cout << "11";
		}else{
			cout  << "10";
		}
	}else{
		if(a[5]>='D'&&a[10]>='D'){
			cout << "11";
		}else{
			cout << "00";
		}
	}
	return 0;
}
