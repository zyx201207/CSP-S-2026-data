#include<bits/stdc++.h>
using namespace std;
long long ans=0;
pair<char,int>arr[500005]; 
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i].second>>arr[i].first;
	int l=1,r=n;
	for(;l<r;l++){
		while(l<r){
			if(arr[l].second-arr[r].second>=0){
				if(arr[l].first!=arr[r].first){
					ans+=arr[r].second;
				} 
				arr[l].second-=arr[r].second;
				r--;
			}
			else{
				if(arr[l].first!=arr[r].first){
					ans+=arr[l].second;
				}
				arr[r].second-=arr[l].second;
				l++; 
			}
		}
	}
	cout<<ans;
	return 0;
}
