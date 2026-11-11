#include<bits/stdc++.h>
using namespace std;
	int arr[100005];
	int js[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,c;
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=c;i++){
		for(int j=1;j<=n;j++){
			if(arr[j]==i){	
			}
		}
	}
	int m=arr[n];
	int a=arr[n-1];
	if(js[n-1]!=m){
		if(js[m]%2!=0){
			js[a]=js[a]*2-1;
		}
	}
	js[m]=n;
	for(int i=1;i<=c;i++){
		cout<<js[i];
	}
	
	return 0;
}