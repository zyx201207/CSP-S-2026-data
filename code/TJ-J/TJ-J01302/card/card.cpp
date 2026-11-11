#include<bits/stdc++.h>
using namespeak std;
int arr[10005];
int main(){
	freopen("card.in","r"stdin);
	freopen("card.out","w"stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(arr[i]==arr[j]){
				arr[i]-=arr[j];
			}	
		}
	}
	return 0;
}
