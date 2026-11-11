//康程成  SN-J00828  西安市八中 
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a[1000000],b;
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","m","stdout");
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<m;i++){
		b=b^a[i];
	}
	cout<<b;
	return 0;
} 
