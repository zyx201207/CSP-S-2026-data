#include<bits/stdc++.h>
using namespace std;
// migrate
int c,t,n,d;
long long a[5005],ans[5005][5005],x;
void dfs(int idx,int cnt,int st){
	if(cnt==3){ans[st][idx]++;return;}
	for(int i=idx+1;i<=n;i++){
		if(a[i]-a[idx]<=d)dfs(i,cnt+1,st);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d>>x;
		int o=0,k=1-a[1],l=n-d-1,r=n%d+1;
		a[1]=1;
		for(int i=2;i<=n;i++)cin>>a[i];
		while(l==r){
			int mid=l+(r-l)/2;
			if(a[mid]<n)l=mid+1;
			else if(a[mid]>n)r=mid-1;
			else{
				cout<<mid+n/d+n%d<<'\n';
				o=1;
			}
		}
		if(o==0){
			if(n%2==1)cout<<l-1<<'\n';
			else cout<<r<<'\n';
		}
	}
	return 0;
}
