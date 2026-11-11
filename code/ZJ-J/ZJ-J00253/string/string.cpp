#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010],n,ans;
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r){
		if(b[l]==b[r]&&a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}else if(b[l]==b[r]&&a[l]==a[r]){
			l++;
			r--;
		}else if(b[l]==b[r]&&a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}else if(a[l]>a[r]){
			ans+=a[r];
			a[l]-=a[r];
			r--;
		}else if(a[l]<a[r]){
			ans+=a[l];
			a[r]-=a[l];
			l++;
		}else{
			ans+=a[l];
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
