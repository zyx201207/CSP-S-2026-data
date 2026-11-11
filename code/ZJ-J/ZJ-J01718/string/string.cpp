#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long n,a[MAXN],ans=0;
char c[MAXN];
void work(){
	int l=1,r=n;
	while(l<r){
		long long cnt=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=cnt;
		}
		a[l]-=cnt;
		a[r]-=cnt;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	work();
	cout<<ans;
	return 0;
}
