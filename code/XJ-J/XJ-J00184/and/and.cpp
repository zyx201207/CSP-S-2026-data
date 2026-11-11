#include <bits/stdc++.h> 
using namespace std;
int arr[2000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n,m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++){
			if(arr[i]==arr[j]){
				cout<<arr[i];
			}
		}
	}
	return 0;
}
