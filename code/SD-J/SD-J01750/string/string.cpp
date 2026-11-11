#include<bits/stdc++.h>
using namespace std;
#define int long long
struct st{
	int a;
	string s;
}arr[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i].a >> arr[i].s;
	}
	int l=1,r=n;
	int ans=0;
	while(l<=r){
		if(arr[l].s==arr[r].s){
			if(arr[l].a>arr[r].a){
				r--;
				arr[l].a-=arr[r+1].a;
			}else if(arr[l].a==arr[r].a){
				r--;
				l++;
			}else{
				l++;
				arr[r].a-=arr[l-1].a;
			}
		}else{
			if(arr[l].a>arr[r].a){
				ans+=arr[r].a;
				r--;
				arr[l].a-=arr[r+1].a;
			}else if(arr[l].a==arr[r].a){
				ans+=arr[r].a;
				r--;
				l++;
			}else{
				ans+=arr[l].a;
				l++;
				arr[r].a-=arr[l-1].a;
			}
		}
	}
	cout << ans;
	return 0;
}
