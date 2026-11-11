#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sz[200005],ans,l,r;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++) cin>>a[i]>>x,sz[i]=x-'a'+1;
	while(l<r){
		if(a[l]<a[r]){
			if(sz[l]==sz[r]) a[r]-=a[l],l++; else ans+=a[l],a[r]-=a[l],l++;
		}else if(a[l]==a[r]){
			if(sz[l]==sz[r]) l++,r--; else ans+=a[l],l++,r--;
		}else{
			if(sz[l]==sz[r]) a[l]-=a[r],r--; else ans+=a[r],a[l]-=a[r],r--;
		}
	}
	cout<<ans;
	return 0;
}
