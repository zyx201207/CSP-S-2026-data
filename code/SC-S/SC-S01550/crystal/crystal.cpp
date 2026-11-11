#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans=1;
bool vis[500005];
bool a1(){
	for(int i=2;i<=n;i++){
		if(a[i]!=i) return 0;
	}
	return 1;
}
bool a2(){
	int c=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=c) return 0;
	}
	return 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a1()){
		for(int i=1;i<=n;i++){
			if(m-i>=0){
				m-=i;
				ans++;
			}
			else break;
		}
		if(ans>=n) cout<<n;
		else cout<<ans;
	}
	else if(a2()){
		int c=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(m-(i*c)>=0){
				m-=(i*c);
				ans++;
			}
			else break;	
		}
		if(ans>=n) cout<<n;
		else cout<<ans;
	}
	else{
		sort(a+1,a+1+n);
		int maxn=1;
		for(int i=2;i<=n;i++){
			int tmp=1;
			int mm=m;
			for(int j=i-1;j>=1;j--){
				if(m-(a[i]-a[j])>=0){
					tmp++;
					m-=((a[i]-a[j]));
				}
			}
			m=mm;
			maxn=max(tmp,maxn);
		}
		cout<<maxn;
	}
	return 0;
}