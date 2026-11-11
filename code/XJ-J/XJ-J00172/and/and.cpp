#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],all,maxn=-1;
bool vis[200010];
void q(int ans,int cnt){
	if(cnt>m){
		maxn=max(ans,maxn);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(cnt==1)ans=a[i];
			q(ans&a[i],cnt+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n==m)all&=a[i];
	}
	if(n==m){
		cout<<all<<endl;
		return 0;
	}
	if(m<n){
		q(0,1);
		cout<<maxn<<endl;
	}
}
