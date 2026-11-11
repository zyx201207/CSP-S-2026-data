#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
long long n,l,r,a[N],ans;
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;r=n;
	while(l<=r){
		if(l==r)break;
		if(a[l]>a[r]){
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r];
			r--;
			continue;
		}
		if(a[l]<a[r]){
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];
			l++;
			continue;
		}
		if(a[l]==a[r]){
			if(c[l]!=c[r])ans+=a[l];
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
