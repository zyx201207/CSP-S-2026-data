#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a;
int ans;

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	int b[100005];
	for(int i=0; i<n; i++){
		cin>>a;
		b[i] = a;
	}
	
	for(int j=0; j<n; j++){
		for(int k=n-1; k>=0; k--){
			swap(b[k],b[k-1]);
		}
	}
	cout<<b[m-1];
	
	return 0;
	
}
