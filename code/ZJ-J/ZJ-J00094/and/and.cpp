#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans=0,c[800001],cnt0=0;
int mx=0;
void dfs(int x,int cnt,int sum){
	if(x>n){
		if(cnt==m)ans=max(ans,sum);
		return ;
	}
	if(cnt>=m){
		if(cnt==m)ans=max(ans,sum);
		return ;
	}
	if(n-x+1<m-cnt)return ;
	dfs(x+1,cnt,sum);
	dfs(x+1,cnt+1,sum&a[x]);
}
void build(int x,int l,int r){
	if(l==r){
		c[x]=a[l];
		return ;
	}
	build(x*2,l,(l+r)/2);
	build(x*2+1,(l+r)/2+1,r);
	c[x]=c[x*2]&c[x*2+1];
}
int ask(int x,int l,int r,int LL,int RR){
	if(l>=LL&&r<=RR)return c[x];
	if(LL>(l+r)/2){
		return ask(x*2+1,(l+r)/2+1,r,LL,RR); 
	}else if(RR<=(l+r)/2){
		return ask(x*2,l,(l+r)/2,LL,RR); 
	}else{
		return ask(x*2,l,(l+r)/2,LL,(l+r)/2)&ask(x*2+1,(l+r)/2+1,r,(l+r)/2+1,RR);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i])cnt0++;
		mx=max(a[i],mx);
	}
	if(cnt0+m>n){
		cout<<0;
		return 0;
	}
	if(n<=2000){
		dfs(1,0,INT_MAX);
		cout<<ans;
	}
	else if(m==n-1){
		build(1,1,n);
		ans=max(ask(1,1,n,2,n),ask(1,1,n,1,n-1));
		for(int i=2;i<n;i++){
			ans=max(ans,ask(1,1,n,1,i-1)&ask(1,1,n,i+1,n));
		}
		cout<<ans;
	}else if(mx<=4){
		int c1=0,c2=0,c3=0,c4=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)c1++;
			if(a[i]==2)c2++;
			if(a[i]==3)c3++;
			if(a[i]==4)c4++;
		}
		if(c4>=m)cout<<4;
		else if(c3>=m)cout<<3;
		else if(c3+c2>=m)cout<<2;
		else if(c3+c1>=m)cout<<1;
		else cout<<0;
	}else{
		sort(a+1,a+n+1,greater<int>());
		int res=INT_MAX;
		for(int i=1;i<=m;i++){
			res&=a[i];
		}
		cout<<res;
	}
	return 0;
}
