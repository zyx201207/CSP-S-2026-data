#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,c;
	bool operator <(const node &a)const{
		return c<a.c;
	}
};
int n,m,a[200005];
priority_queue<node>q;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int f=1,g=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((int)log2(a[i]+1)!=log2(a[i]+1)){
			f=0;
		}
		if(a[i]!=i-1){
			g=0;
		}
	}
	sort(a+1,a+n+1,greater<int>());
	if(f==1){
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(g==1&&(int)log2(n)==log2(n)){
		int ans=n;
		int res=1;
		while(res<m){
			res<<=1;
		}
		ans-=res;
		cout<<ans;
		return 0;
	}
	if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					mx=max(mx,a[i]&a[j]);
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
			
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	int x,mx=-1;
	for(int i=1;i<=n;i++){
		int res=a[i],cnt=0;
		while(res){
			if(res&1){
				cnt++;
			}
			res>>=1;
		}
		if(mx<cnt){
			mx=cnt;
			x=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(i==m) continue;
		int res1=a[i],res2=x,cnt=0;
		int res=res1&res2;
		while(res){
			if(res&1){
				cnt++;
			}
			res>>=1;
		}
		q.push({i,cnt});
	}
	int cnt=0,ans=x;
	while(!q.empty()){
		int u=q.top().x;
		q.pop();
		cnt++;
		ans=ans&a[u];
		if(cnt==m-1){
			cout<<ans;
			return 0;
		}
	}
	
	return 0;
}
