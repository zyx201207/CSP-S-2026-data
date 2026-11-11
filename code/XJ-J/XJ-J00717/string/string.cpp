#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long arr[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			ans+=min(arr[l],arr[r]);
		}
		if(arr[l]>arr[r]){
			arr[l]-=arr[r];
			r--;
		}
		else if(arr[l]<arr[r]){
			arr[r]-=arr[l];
			l++;
		}
		else l++,r--;
	}
	cout<<ans;
	return 0;
} 
