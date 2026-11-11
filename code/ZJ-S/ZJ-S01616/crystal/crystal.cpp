#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000010],b[1000010],c[1000010],ss,ans,t;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		c[i]=c[i-1]+b[i];
	}for(int i=1;i<n;i++){
		ss+=b[i]*(i-t);
		while(ss>m){
			ss-=c[i]-c[t];
			t++;
		}ans=max(ans,i-t+1);
	}cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 3
-100 1 2 3 4


*/
