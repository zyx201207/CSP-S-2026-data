#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200010],mid,l,r,l2;
char b[200010];
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		mid+=a[i];
	}
	r=n;
	l=1;
	mid/=2;
	while(l2<mid){
		l2+=min(a[l],a[r]);
		if(b[l]!=b[r]){
			ans+=min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}else if(a[l]==a[r]){
			l++;
			r--;
		}else if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}
		
	}
	cout<<ans;
	return 0;
}
