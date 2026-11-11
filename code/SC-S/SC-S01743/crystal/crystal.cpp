#include<bits/stdc++.h>
using namespace std;
int arr[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=arr[n-1];i>=arr[0];i--){
		int mm=m;
		for(int j=n-1,num=0;j>=0;j--){
			mm-=(i-arr[j]);
			if(mm<=0){
				ans=max(ans,num);
				break;
			}
			num++;
		}
	}
	cout<<ans;
	return 0;
}