 #include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,ans=0;
	while(l<r){
		while(a[r]){
			int s=min(a[r],a[l]);
			a[r]-=s;
			a[l]-=s;
			if(c[l]!=c[r]){
				ans+=s;
			}
			if(a[l]==0){
				l++;
			}
			if(l==r){
				break;
			}
		}
		r--;
	}
	cout<<ans;
	return 0;
}
