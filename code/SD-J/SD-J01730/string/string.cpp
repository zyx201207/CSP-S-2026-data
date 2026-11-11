#include<bits/stdc++.h> 
using namespace std;
long long a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i]>>b[i];
	long long l=1,r=n,ans=0;
	while(l<r){
		long long minn=min(a[l],a[r]);
		a[l]-=minn,a[r]-=minn;
		if(b[l]!=b[r]) ans+=minn;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}

