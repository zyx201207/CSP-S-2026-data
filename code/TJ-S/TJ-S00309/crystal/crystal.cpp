#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[500005]={};
int crr[500005]={};
int qrr[500005]={};
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=2;i<=n;i++){
		crr[i]=arr[i]-arr[i-1];
		qrr[i]=crr[i]+qrr[i-1];
	}
	int ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int s=qrr[j]-qrr[i-1]; 
			if(s<=m){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
