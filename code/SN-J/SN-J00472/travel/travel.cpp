#include<bits/stdc++.h>
using namespace std;
int main(){
	char n[15];
	int i=0;
	cin.get(n,15);
	if(n[0]==n[7]&&n[1]==n[8]){
		cout<<1;
		i++;
		if(n[3]==n[10]&&n[4]==n[11]){
			cout<<1;
			i++;
			if((n[5]<='B'&&n[12]<='B')||(n[5]>='C'&&n[12]>='C')){
				cout<<1;
				i++;
				if(abs(n[5]-n[12])==1){
					cout<<1;
					i++;
				}
			}
		}
	}
	for(int s=4;s>i;s--){
		cout<<0;
	}
	return 0;
}
