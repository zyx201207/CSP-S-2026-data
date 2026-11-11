#include <bits/stdc++.h>
using namespace std;
long long arr[200005],m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(m==1){
		int maxn=0;
		for(int i=0;i<n;i++){
			if(arr[i]>maxn){
				maxn=arr[i];
			}
		cout<<arr[i];
		return 0;
		}
	}
	if(m==n){
		int ans=arr[0];
		for(int i=1;i<n;i++){
			ans=ans&arr[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int maxn=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(arr[i]&arr[j]>maxn){
					maxn=arr[i]&arr[j];
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}
