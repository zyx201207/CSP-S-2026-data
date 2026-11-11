#include<bits/stdc++.h>
using namespace std;
int a[210000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1,a+m+1);
	cout<<a[m/2]+1;
	return 0;
} 
