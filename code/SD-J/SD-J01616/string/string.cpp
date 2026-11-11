#include <bits/stdc++.h>
using namespace std;
const long long MAXN=2e5+10;
long long n,a[MAXN],ans=0;
char c[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}long long l=1,r=n;
	while(l<r){
		if(l==r) break;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
		}long long p=a[l];
		a[l]=max(0ll,a[l]-a[r]);
		a[r]=max(0ll,a[r]-p);
	}cout<<ans;
	return 0;
}/*
*/
