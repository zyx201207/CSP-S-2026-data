#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define int long long  
int a[maxn];
int b[maxn];
int n,m;
int work(int x){
	int sz=a[x];
	int res=0;
	int sum=m;
	for(int i=1;i<=n;i++){
		b[i]=max(0ll,sz-a[i]);
	}
	for(int i=x;i>=1;i--){
		if(sum>=b[i]){
			res++;
			sum-=b[i];
		}
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int drt=a[2]-a[1];
	bool f=1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=drt){
			f=0;
			break;
		}
	}
	if(f==1){
		cout<<work(n);
		return 0;
	}
	int ans=0;
	if(n<=5005){
		for(int i=n;i>=1;i--){
		if(ans>=i){
			break;
		}
		ans=max(ans,work(i));
	   }
	   cout<<ans;
	   return 0;
	} 
	int r=1;
	int sum=a[2]-a[1];
	for(int l=2;l<=n;l++){
		int sz=l-r+1;
		sum+=(a[l]-a[l-1])*(sz-1);
		while(sum>m){
			r++;
			sum-=a[l]-a[r];
		}
		sz=l-r+1;
		ans=max(ans,sz);
	}
	cout<<ans;
}
