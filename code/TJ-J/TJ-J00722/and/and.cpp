#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx = -1;
	cin>>n>>m;
	int a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(i == j) continue;
			if((a[i] and a[j])>maxx) maxx = a[i] and a[j];
		}
	}
	cout<<maxx;
	return 0;
} 
