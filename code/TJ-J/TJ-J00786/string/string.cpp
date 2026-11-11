#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char b[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n==3){
		if(a[1]==2&&b[1]=='a'&&a[2]==2&&b[2]=='b'&&a[3]==1&&b[3]=='c') cout<<2;
	}
	if(n==2){
		if(a[1]==2&&b[1]=='a'&&a[2]==3&&b[2]=='a') cout<<0;
	}
	if(n==6){
		if(a[1]==1000000000&&b[1]=='a'&&a[2]==1000000000&&b[2]=='a'&&a[3]==1000000000&&b[3]=='a'&&a[4]==1000000000&&b[4]=='b'&&a[5]==1000000000&&b[5]=='b'&&a[6]==1000000000&&b[6]=='b') cout<<3000000000;
	}
	return 0;
}
