#include<bits/stdc++.h>
using namespace std;
char a[20];
int b[10];
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	for(int i=1;i<=10;i++){
			cin>>a[i];
	}

	for(int i=1;i<=10;i++){
		if(int(a[i])<=57&&int(a[i])>=48){
		b[i]=int(a[i])-48;
		}
	}
	if(b[1]==b[6]&&b[2]==b[7]){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b[3]==b[8]&&b[4]==b[9]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((int(a[5])<=67&&int(a[10])<=67)||(int(a[5])>67&&int(a[10])>67)){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(int(a[5])-int(a[10]))==1||(int(a[5])>67&&int(a[10])>67)){
		cout<<1;
		
	}

	else{
		cout<<"0";
	
		return 0;
		
	}
	return 0;
}