#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[200000];
	int c=0;
	for(int i=0;i<n;i++){
		int aii;
		char cii;
		cin>>aii>>cii;
		for(int j=c;j<c+aii;j++){
			a[j]=int(cii);
		}
		c+=aii;
	}
	int s=0;
	for(int i=0;i<c/2+1;i++){
		if(a[c-i-1]!=a[i]){
			s++;
		}
	}
	cout<<s;
	return 0;
}

