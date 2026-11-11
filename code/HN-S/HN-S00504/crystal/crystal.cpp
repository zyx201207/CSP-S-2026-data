#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[514514],M,ans,s[514514];
map<int,int> mp;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> M;
	for(int i=1;i<=n;i++){
		cin >> a[i];
//		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int asd=mp[a[i]];
		int l=0,r=i;
		while(l+1<r){
			int m=(l+r)/2;
			__int128 as=a[i];
			__int128 sa=as*(i-m)-(s[i-1]-s[m-1]);
//			cout << a[i]*(i-m)-(s[i-1]-s[m-1]) << '\n';
			if(sa>M){
				l=m;
			}else{
				r=m;
			}
		}
//		cout << i << ' ' << a[i] << ' ' << r << '\n';
		ans=max(ans,i-r+1);
	}
	cout << ans;
	return 0;
}
