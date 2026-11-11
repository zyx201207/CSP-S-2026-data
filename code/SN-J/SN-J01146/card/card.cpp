#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k=0;
	int v=0;
	int num[m+1]={0};
	while(k<n){
		int sum[n]={0}; 
		for(int i=k;i<n;i++){
			sum[i]=arr[i];
			for(int j=k-1;j>=0;j--){
				if(arr[j]==sum[j]){
					for(int l=j;l>=0;l--){
						if(arr[l]==sum[l]){
							sum[l]==0;
							break;
						}
						sum[l]==0;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			num[sum[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
