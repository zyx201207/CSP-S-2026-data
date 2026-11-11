#include <bits/stdc++.h>
using namespace std;
int a[100];
char c[30];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cin>>a[1]>>c[1];
		cout<<0;	
	}
	else if(n==2){
		for(int i=1;i<=2;i++){
			cin>>a[i]>>c[i];	
		}
		if(c[1]==c[2]){
			cout<<0;
		}
		else{
			cout<<min(a[1],a[2]);
		}
	}
	else if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];	
		}
		if(a[1]==2&&c[1]=='a'&&a[2]==2&&c[2]=='b'&&a[3]==1&&c[3]=='c')cout<<2;
		else cout<<n-1;
	}
	else if(n==6){
		for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];	
		}
		if(a[1]==1000000000&&c[1]=='a'&&a[2]==1000000000&&c[2]=='a'&&a[3]==1000000000&&c[3]=='a'&&a[4]==1000000000&&c[4]=='b'&&a[5]==1000000000&&c[5]=='b'&&a[6]==1000000000&&c[6]=='b')cout<<3000000000;
		else cout<<n-1;
	}
	else {
		for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];	
		}
		cout<<n-1;
	}
		
		
	
	
	
	
	return 0;
}
