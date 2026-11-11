#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	string x,v;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int k=1;k<=a;k++){
			x[k]=c;
		}
	}
	int j=1;
	for(int i=n;i>=1;i--){
		v[j]=x[i];
		j++;
	}
	for(int i=1;i<=n;i++){
		if(v[i]!=x[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}