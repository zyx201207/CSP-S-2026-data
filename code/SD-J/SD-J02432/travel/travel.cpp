#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[20],b[20];
	char x,y,c;
	for(int i=1;i<=4;i++){
		cin>>a[i];
		for(int j=1;j<=4;j++){
			cin>>b[j];
		}	
	}
	if(a[x]!=b[x]){
		cout<<"0000";
	}else if(a[y]!=b[y]){
		cout<<"1000";
	}else if(a[c]=='A'&&a[c]=='C'){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}
