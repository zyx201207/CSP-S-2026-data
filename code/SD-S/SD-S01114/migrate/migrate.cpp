#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[5005],ans,cnt,sum;
int gE(int x,int y){
	int id=x,cNt=0;
	while(id<y){
		int l=id,r=y;
		while(l<r){
			int mid=(l+r+1)/2;
			if(a[mid]-a[id]<=d)l=mid;
			else r=mid-1;
		}
		if(l==id)return 0;
		cNt++;
		id=l;
	}
	return cNt;
}
void dfs(int l,int r,int dd){
	if(l==r){
		if(ans==dd){
			cnt++;
		}
		return ;
	}
	for(int i=l+1;i<=r;i++){
		if(a[i]-a[l]<=d)dfs(i,r,dd+1);
	}
}
void oper(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(c==13||c==14){
		cout<<0<<'\n';
		return ;
	}
	sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=gE(i,j);
			cnt=0;
			dfs(i,j,0);
			if(ans&&cnt==2){
				sum++;
			}
		}
	}
	cout<<sum<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)oper();
	return 0;
}
