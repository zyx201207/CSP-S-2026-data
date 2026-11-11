#include <bits/stdc++.h>
using namespace std;
int n,k=0;
int a[100005];
string c[200005];
string x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<a[i];j++){
			x += c[i];
			k+=1;
		}
	}
	if(x[0] == x[k-1]){
		cout<<0;
	}
	else cout<<a[0];
	return 0;
}
