#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char c;
	string x; 
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			x=x+c;
		}
	}
	int l=x.size(),cnt=0;
	for(int i=0;i<l/2;i++){
		if(x[i]!=x[l-i-1]){
			x[l-i-1]=x[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
