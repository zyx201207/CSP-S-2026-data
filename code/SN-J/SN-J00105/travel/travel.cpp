#include<bits/stdc++.h>
using namespace std;
char a[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=10;i++){
		cin>>a[i];
	}
	if(a[1] != a[6]  || a[2]!=a[7]){
		cout<<"0000";
		return 0;
	}
	if(a[3] != a[8]  || a[4]!=a[9]){
		cout<<"1000";
		return 0;
	}
	if(a[5] =='A' && a[10]=='B'){
		cout<<"1111";
		return 0;
	}
    if(a[5] =='B' && (a[10]=='A' || a[10]=='C')){
		cout<<"1111";
		return 0;
	}
	if(a[5] =='C' && a[10]=='B'){
		cout<<"1111";
		return 0;
	}
	if(a[5] =='D' && a[10]=='F'){
        cout<<"1111";
		return 0;
		}
	if(a[5] =='F' && a[10]=='D'){
		cout<<"1111";
		return 0;
		}
	if((a[5]=='C'|| a[5]=='D') && (a[10]=='D' || a[10]=='C')){
			cout<<"1100";
			return 0;
	}
	cout<<"1110";
	return 0;
}
