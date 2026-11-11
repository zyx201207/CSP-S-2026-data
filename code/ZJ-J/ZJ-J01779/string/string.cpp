#include<bits/stdc++.h>
using namespace std;
char c[200100];
int n,l,r,a[200100];
long long lx,rx,k,sz,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	if(n<=1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sz+=a[i];
	}
	l=0,r=n+1,lx=0,rx=0,k=0;
	while(l<r){
		if(lx<rx){
			l++;
			lx+=a[l];
			if(c[l]!=c[r]) ans+=min(lx-k,rx-k);
			k=min(lx,rx);
		}
		else if(lx>rx){
			r--;
			rx+=a[r];
			if(c[l]!=c[r]) ans+=min(lx-k,rx-k);
			k=min(lx,rx);
		}
		else{
			l++,r--;
			lx+=a[l];
			rx+=a[r];
			if(c[l]!=c[r]) ans+=min(lx-k,rx-k);
			k=min(lx,rx);
		}
		
	}
	cout<<ans;
	return 0;
}