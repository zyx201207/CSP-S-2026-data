#include<bits/stdc++.h>
using namespace std;
long long n,l,r,s,a[200005];char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;l=1;r=n;
	for (int i=1;i<=n;i++) cin>>a[i]>>c[i];
	while (l<r){
		if (a[l]>a[r]){
			a[l]-=a[r];
			if (c[l]!=c[r]) s+=a[r];
			r--;
		}else if (a[l]==a[r]){
			if (c[l]!=c[r]) s+=a[r];
			l++;r--;
		}else{
			a[r]-=a[l];
			if (c[l]!=c[r]) s+=a[l];
			l++;
		}
	}cout<<s;
}
