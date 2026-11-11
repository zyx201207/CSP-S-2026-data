#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,arr[N],ans;
char c[N]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i]>>c[i];
	}
	for(int l=1,r=n;l<=r;){
		if(c[l]==c[r]){
			if(arr[l]==arr[r]){
				l++;
				r--;
			}
			else if(arr[l]<arr[r]){
				arr[r]-=arr[l];
				l++;
			}
			else{
				arr[l]-=arr[r];
				r--;
			}
		}
		else{
			if(arr[l]==arr[r]){
				ans+=arr[l];
				l++;
				r--;
			}
			else if(arr[l]<arr[r]){
				arr[r]-=arr[l];
				ans+=arr[l];
				l++;
			}
			else{
				arr[l]-=arr[r];
				ans+=arr[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
