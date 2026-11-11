#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200001];
	char c[200001];
	string b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		if(c[i]!=c[i+1]){
			return 0;
		}
	}
	cout<<"0";
	return 0;
}