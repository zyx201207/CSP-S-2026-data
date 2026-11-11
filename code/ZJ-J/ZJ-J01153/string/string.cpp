#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N],n,ans;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	ll l=1,r=n;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]==a[r]){l++;r--;continue;}
			if(a[l]>a[r]){a[l]-=a[r];r--;continue;}
			if(a[l]<a[r]){a[r]-=a[l];l++;continue;}
		}else{
			if(a[l]==a[r]){
				ans+=a[l];
				l++,r--;
				continue;
			}
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
				continue;
			}
			if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}