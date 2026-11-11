#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long s[200005],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
	}
	int wz=lower_bound(s+1,s+n+1,s[n]/2)-s;
	int l=1,r=n;
	char lop=c[1],rop=c[n];
	while(l<r){
		if(a[l]>a[r]){
			if(lop!=rop) ans+=a[r];
			a[l]-=a[r];
			r--;
			rop=c[r];
		}
		else{
			if(lop!=rop) ans+=a[l];
			a[r]-=a[l];
			l++;
			lop=c[l];
		}
	}
	cout<<ans<<'\n';
	return 0;
}