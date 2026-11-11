#include<bits/stdc++.h>
using namespace std;
int a[2005];
int main(){
	freopen("and.in",'r',stdin);
	freopen("and.out",'w',stdout);
	int n,m;
	cin>>n>>m;
	int max = 0;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		if(a[i] > max) max = a[i];
	}
	if(m == 1) cout<<max;
	else if(m == n) {
		int count = a[0];
		for(int i = 1;i<n;i++){
			count = count & a[i];
		}
	}
	return 0;
}
