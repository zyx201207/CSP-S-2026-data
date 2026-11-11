#include <bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	int a[100100];
	freopen(".in","r",stdin);
	freopen(".out","w",stdout); 
	cin>>m>>n;
	for(int i = 1;i++;i<=m){
		cin>>a[i];
		if(a[i]>a[i+1])swap(a,i,i+1);
	}
	cout<<a[m];
	return 0;
} 
