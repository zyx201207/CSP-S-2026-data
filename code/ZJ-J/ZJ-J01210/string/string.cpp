#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]==a[r]){
				l++,r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
		}else{
			if(a[l]==a[r]){
				sum+=a[l];
				l++,r--;
			}else if(a[l]<a[r]){
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				sum+=a[r];
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}