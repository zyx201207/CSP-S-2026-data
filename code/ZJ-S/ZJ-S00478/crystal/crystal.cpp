#include<bits/stdc++.h>
using namespace std;

long long a[500005],n,m,l,r,cnt,ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n+1]=a[n];
	sort(a+1,a+n+1);
	l=r=1;
	cnt=0;//»¨·Ñ
	while(r<n){
		r++;
		cnt+=(r-l)*(a[r]-a[r-1]);
		while(cnt>m){
			cnt-=a[r]-a[min(l++,r)];
		}
		if(l>r)l=r;
		ans=max(r-l+1,ans);
	}
	cout<<ans;
	return 0;
}
