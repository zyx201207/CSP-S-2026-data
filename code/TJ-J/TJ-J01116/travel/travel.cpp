#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a1,b1;
	int len=a1.size();
	cin>>a>>a1>>b>>b1;
	if(a==b) cout<<1;
	else {
	cout<<0<<0<<0<<0;
	return 0;
}
	if(a1[0]==b1[0]){
		if(a1[1]==b1[1]){
			cout<<1;
			if(a1[2]>='A'&&a1[2]<='C'&&b1[2]>='A'&&b1[2]<='C'){
				cout<<1;
				if(a1[2]-b1[2]==1||b1[2]-a1[2]==1){
					cout<<1;
				}else cout<<0;
			}else if(a1[2]=='D'&&a1[2]=='F'&&b1[2]=='D'&&b1[2]=='F'){
				cout<<1<<1;
			}else cout<<0<<0;
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0;
	}
	return 0;
}
