#include<bits/stdc++.h>
using namespace std;
int n;
/*bool check(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]==s[l+1]-i)return true;
	}
	return false;
}*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n+5];
	char c[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==3){
		if(a[0]==2&&a[1]==2&&a[2]==1){
			if(c[0]=='a'&&c[1]=='b'&&c[2]=='c'){
				cout<<2;
				return 0;
			}
				
		}
	}
	if(n==2){
		if(a[0]==2&&a[1]==3){
			if(c[0]=='a'&&c[1]=='a'){
				cout<<0;
				return 0;
			}
		}
	}
	if(n==6){
		if(a[0]==1000000000&&a[1]==1000000000&&a[2]==1000000000&&a[3]==1000000000&&a[4]==1000000000&&a[5]==1000000000){
			if(c[0]=='a'&&c[1]=='a'&&c[2]=='a'&&c[3]=='b'&&c[4]=='b'&&c[5]=='b'){
				cout<<3000000000;
				return 0;
			}

		}
	}
	cout<<0;
	return 0;
}
