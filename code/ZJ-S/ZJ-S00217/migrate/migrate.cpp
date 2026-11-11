#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int c,t,n,d,a[N],f[N],ans,dp[N];
int mn,cnt;
deque<int>q;
struct node{
	int p,l,r,mn=1e9,sum;
}tree[4*N];
void push_up(int k){
	int m1=tree[k*2].mn;
	int m2=tree[k*2+1].mn;
	if(m1==m2){
		tree[k].mn=m1;
		tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
	}if(m1>m2){
		tree[k].mn=tree[k*2+1].mn;
		tree[k].sum=tree[k*2+1].sum;
	}if(m1<m2){
		tree[k].mn=tree[k*2].mn;
		tree[k].sum=tree[k*2].sum;
	}
}
void build(int p,int l,int r){
	tree[p].l=l;
	tree[p].r=r;
	if(l==r){
		tree[p].mn=dp[l];
		tree[p].sum=1;
		return;
	}
	int mid=(l+r)/2;
	int x=p*2;
	int y=p*2+1;
	build(x,l,mid);
	build(y,mid+1,r);
	push_up(p);
}
void query(int p,int l,int r){
	if(tree[p].l>=l and tree[p].r<=r){
		if(tree[p].mn==mn){
			cnt+=tree[p].sum;
		}
		if(tree[p].mn<mn){
			mn=tree[p].mn;
			cnt=tree[p].sum;
		}return;
	}
	int mid=(tree[p].l+tree[p].r)/2;
	if(mid>=l)query(p*2,l,r);
	if(mid<r)query(p*2+1,l,r);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=4*n;i++)tree[i].mn=1e9;
		ans=0;
		cin>>n>>d;
		dp[1]=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		int r=1;
		for(int i=1;i<=n;i++){
			while(a[i]-a[r]>d and r<=i)r++;
			f[i]=r;
		}
		q.push_back(1);
		for(int i=2;i<=n;i++){
			while(!q.empty() and a[i]-a[q.front()]>d)q.pop_front();
			dp[i]=dp[q.front()]+1;
			while(!q.empty() and dp[i]<=dp[q.back()])q.pop_back();
			q.push_back(i);
		}build(1,1,n);
		for(int i=1;i<=n;i++){
			mn=1e9;
			cnt=0;
			query(1,f[i],i-1);
			if(cnt==2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
