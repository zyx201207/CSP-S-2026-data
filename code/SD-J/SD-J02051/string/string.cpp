#include <bits/stdc++.h>
using namespace std;
char c[10000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0;
	int a[200001];
	int b[200001],mm=0;
	char x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>x;
		for(int j=0;j<a[i];j++){
			c[l]=x;
			l++;
		}
	}
	for(int i=0;i<(l/2+l%2);i++){
		if(c[l-i-1]!=c[i]){
			mm++;
		}
	}
	cout<<mm;
	return 0;
}
