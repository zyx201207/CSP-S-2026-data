#include "bits/stdc++.h"
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1,cmp);
	cout<<a[2];
	
}