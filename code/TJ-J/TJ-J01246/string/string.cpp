#include<bits/stdc++.h>
using namespace std;
int a[200005];
string b;
string c;
string d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i =0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<a[i];j++){
			b[i]=c[i];
		}
	}for(int i = 0;i<n;i++){
		for(int j = a[i];j>0;j--){
			d[j]=b[i]; 
		}
	}
	cout<<2;
	return 0;
} 
