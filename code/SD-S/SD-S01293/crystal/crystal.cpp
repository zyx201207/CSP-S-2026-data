#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int n,m,ans;
int a[500010];
signed main(){
	fast;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int cnt=0,lst=1;
	for(int i=1;i<=n;i++){
		if(lst<i) lst=i;
		while(lst<n&&cnt+(lst-i+1)*(a[lst+1]-a[lst])<=m){
			cnt+=(lst-i+1)*(a[lst+1]-a[lst]);
			lst++;
		}
		if(lst-i+1>ans){
			ans=lst-i+1;
		}
		cnt+=a[i];
		cnt-=a[lst];
	}
	cout<<ans;
	return 0;
}

