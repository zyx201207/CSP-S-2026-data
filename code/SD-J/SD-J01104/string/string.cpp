#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int l=1,r=n;l<=r;){
		if(c[l]!=c[r]){
			int t=min(a[l],a[r]);
			ans+=t;
			a[l]-=t;
			a[r]-=t;
			if(a[l]==0){
				l++;
			}
			else{
				r--;
			}
		}
		else{
			int t=min(a[l],a[r]);
			a[l]-=t;
			a[r]-=t;
			if(a[l]==0){
				l++;
			}
			else{
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
