#include<bits/stdc++.h>
using namespace std;
char a[10],b[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<5;i++){
		cin>>a[i];
	}
	for(int i=0;i<5;i++){
		cin>>b[i];
	}
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<"1";
		if(a[2]==b[2]&&a[3]==b[3]){
			cout<<"1";
			if((int(b[4])<=int('C')&&int(a[4])<=int('C'))||(int(a[4])>int('C')&&int(b[4])>int('C'))){
				cout<<"1";
				if(abs(int(a[4])-int(b[4]))==1)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
}

