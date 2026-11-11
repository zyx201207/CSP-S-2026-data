#include<bits/stdc++.h>
using namespace std;
char a[10],b[10];
int main(){
	for(int i=1;i<=5;i++)	cin>>a[i];
	for(int i=1;i<=5;i++)	cin>>b[i];
	if(a[1]==b[1]&&a[2]==b[2]){
		cout<<1;
		if(a[3]==b[3]&&a[4]==b[4]){
			cout<<1;
			if(int(a[5])<=67&&int(b[5])<=67||int(a[5])>67&&int(b[5])>67){
				cout<<1;
				if(abs(int(a[5])-int(b[5]))==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}	
	return 0;
}