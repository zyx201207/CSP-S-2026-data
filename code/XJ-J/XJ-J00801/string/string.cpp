#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[2100000];
	string c[2100000],x=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++){
			x==x+c[i];
		}
	}
	cout<<x;
	return 0;
}