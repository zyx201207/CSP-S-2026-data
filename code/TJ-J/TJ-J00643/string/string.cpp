#include <bits/stdc++.h>
using namespace std;
int n;
long long l,r,ans;
char ch[200005];
int arr[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i]>>ch[i];
	}
	l=1;
	r=n;
	while(l<r){
		if(ch[l]==ch[r]){
			if(arr[l]<arr[r]){
				arr[r]-=arr[l];
				arr[l]=0;
				l++;
			}else if(arr[l]>arr[r]){
				arr[l]-=arr[r];
				arr[r]=0;
				r--;
			}else{
				arr[l]=arr[r]=0;
				l++;
				r--;
			}
		}else{
			if(arr[l]<arr[r]){
				arr[r]-=arr[l];
				ans+=arr[l];
				arr[l]=0;
				l++;
			}else if(arr[l]>arr[r]){
				arr[l]-=arr[r];
				ans+=arr[r];
				arr[r]=0;
				r--;
			}else{
				ans+=arr[l];
				arr[l]=arr[r]=0;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
