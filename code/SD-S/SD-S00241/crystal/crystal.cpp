#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,a[N],s[N],fans[N],ans,b[N];
int erf(int x,int l,int r){
	while(l<r){
		int mid=(l+r)>>1;
		if(x<-s[l]){
			r=mid-1;
		}else{
			l=mid;
		}
	}
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	if(n<=10000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+a[i];
		}
		for(int l=0;l<n;l++){
			for(int r=l;r<=n;r++){
				if((r-l)*a[r]-s[r]+s[l]<=m){
					ans=max(ans,r-l);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		fans[i]=-s[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=i*a[i]-s[i]-m;
	}
	for(int r=1;r<=n;r++){
		if(b[r]<=0){
			ans=max(ans,r);
			continue;
		}
		int l=lower_bound(fans+1,fans+r,b[r])-fans-1;
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

7 20
-10000 1 2 3 4 5 7
-20 9981 9983 9986 9990 9995 10007
*/
