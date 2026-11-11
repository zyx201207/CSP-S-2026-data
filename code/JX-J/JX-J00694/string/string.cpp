#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
char s[N];
long long ans,n,a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(s[l]==s[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]==a[r]){
				l++;
				r--;
			}else{
				a[l]-=a[r];
				r--;
			}
		}else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}else if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}else{
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
