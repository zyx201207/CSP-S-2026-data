#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans;
struct ask{
	ll a;
	char c;
}arr[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].a>>arr[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(arr[l].a==arr[r].a){
			if(arr[l].c!=arr[r].c){
				ans+=arr[l].a;
			}
			l++;
			r--;
			continue;
		}
		if(arr[l].a<arr[r].a){
			if(arr[l].c!=arr[r].c){
				ans+=arr[l].a;
			}
			l++;
			arr[r].a-=arr[l].a;
			continue;
		}
		if(arr[l].a>arr[r].a){
			if(arr[l].c!=arr[r].c){
				ans+=arr[r].a;
			}
			r--;
			arr[l].a-=arr[r].a;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
