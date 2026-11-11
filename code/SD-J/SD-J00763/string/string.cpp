#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
int n;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,ans=0;
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]==c[r]){
				++l,--r;
				continue;
			}
			else{
				ans+=a[l];
				++l,--r;
				continue;
			}
		}
		else{
			if(a[l]<a[r]){
				if(c[l]!=c[r]) ans+=a[l];
				a[r]-=a[l];
				l++;
			}
			else{
				if(c[l]!=c[r]) ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 

