#include<bits/stdc++.h>
using namespace std;
int n,a[200005],l,r;
long long len,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	l=1,r=n;
	if(n==1){
		cout<<0;
		return 0;
	}
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]!=c[r])ans+=a[r];
			a[l]=0;
			a[r]=0;
			l++;
			r--;
		}else if(a[l]<a[r]){
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];
			a[l]=0;
			l++;
		}else{
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
