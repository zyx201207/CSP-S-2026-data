#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		arr[i]=a;
	}
	cout<<arr[n-1];
	return 0;
}