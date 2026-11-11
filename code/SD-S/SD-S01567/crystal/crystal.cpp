#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,ans=-1;
int cnt,mx; 
int a[N],d[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//特殊性质 
	int x=a[2]-a[1],flag=0;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=x)
			flag=1;
	}
	if(flag==0){
		int s=0;
		for(int i=1;i<=n;i++){
			d[i]=d[i-1]+x;
		}
		for(int i=1;i<=n;i++){
			int sum=(d[1]+d[i])*i/2;
			if(sum>m)break;
			s=i;
		}
		cout<<s+1;
		return 0;
	} 
	//暴力 
	for(int i=1;i<=n;i++){
		cnt=0,mx=m;
		for(int j=i;j>=1;j--){
			mx-=(a[i]-a[j]);
			if(mx>=0)cnt++;
			else break;
		}
		ans=max(ans,cnt);
	} 
	cout<<ans;
	return 0;
} 
