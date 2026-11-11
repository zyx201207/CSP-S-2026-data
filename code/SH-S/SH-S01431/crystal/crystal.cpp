#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r=0,ans=0,tempm=0,tempans=1,templ;
long long m;
int a[500005],b[500005];
inline void add() {
	tempm+=tempans*b[++r];
	templ+=b[r];
	tempans++;
	if(tempm<=m&&tempans>ans) ans=tempans;
}
inline void del() {
	tempm-=templ;
	templ-=b[l];
	l++;
	tempans--;
	if(tempm<=m&&tempans>ans) ans=tempans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) {
		b[i]=a[i+1]-a[i];
	}  
	while(r<=n-2&&l<=n-2) {
		while(tempm<=m&&r<=n-2&&l<=n-2) add();
		while(tempm>m&&r<=n-2&&l<=n-2) del();
	}
	cout<<ans;
	return 0;
}
