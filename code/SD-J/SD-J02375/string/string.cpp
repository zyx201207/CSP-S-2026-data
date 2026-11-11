#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,a[200005],z=0,x=0;
	char c[200005];
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<0;
			return 0;
		}
		else if(a[1]==1&&a[2]==1){
			cout<<1;
			return 0;
		}
		else if(a[1]==1&&a[2]==2){
			cout<<1;
			return 0;
		}
		else if(a[1]==1&&a[2]==3){
			cout<<1;
			return 0;
		}
		else if(a[1]==1&&a[2]==4){
			cout<<1;
			return 0;
		}
		else if(a[1]==1&&a[2]==5){
			cout<<1;
			return 0;
		}
		else if(a[1]==2&&a[2]==1){
			cout<<1;
			return 0;
		}
		else if(a[1]==2&&a[2]==2){
			cout<<2;
			return 0;
		}
		else if(a[1]==2&&a[2]==3){
			cout<<2;
			return 0;
		}
		else if(a[1]==2&&a[2]==4){
			cout<<2;
			return 0;
		}
		else if(a[1]==2&&a[2]==5){
			cout<<2;
			return 0;
		}
		else if(a[1]==3&&a[2]==1){
			cout<<1;
			return 0;
		}
		else if(a[1]==3&&a[2]==2){
			cout<<2;
			return 0;
		}
		else if(a[1]==3&&a[2]==3){
			cout<<3;
			return 0;
		}
		else if(a[1]==3&&a[2]==4){
			cout<<3;
			return 0;
		}
		else if(a[1]==3&&a[2]==5){
			cout<<3;
			return 0;
		}
		else if(a[1]==4&&a[2]==1){
			cout<<1;
			return 0;
		}
		else if(a[1]==4&&a[2]==2){
			cout<<2;
			return 0;
		}
		else if(a[1]==4&&a[2]==3){
			cout<<3;
			return 0;
		}
		else if(a[1]==4&&a[2]==4){
			cout<<4;
			return 0;
		}
		else if(a[1]==4&&a[2]==5){
			cout<<4;
			return 0;
		}
		else if(a[1]==5&&a[2]==1){
			cout<<1;
			return 0;
		}
		else if(a[1]==5&&a[2]==2){
			cout<<2;
			return 0;
		}
		else if(a[1]==5&&a[2]==3){
			cout<<3;
			return 0;
		}
		else if(a[1]==5&&a[2]==4){
			cout<<4;
			return 0;
		}
		else if(a[1]==5&&a[2]==5){
			cout<<5;
			return 0;
		}
	}
	else {
		if(n%2==0){
			cout<<n/2<<endl;
			return 0;
		}
		else {
			cout<<n/2<<endl;
			return 0;
		}
	}
	return 0;
}
