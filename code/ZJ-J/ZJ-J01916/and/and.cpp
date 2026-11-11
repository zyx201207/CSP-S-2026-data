//OK
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],cnt[35],c[N],ans;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int u,int k){
	if(u>n){
		if(k!=m)return;
		int anss=0;
		int i=1;
//		for(int i=1;i<=n;++i)cout<<c[i]<<' ';
//		cout<<'\n';
		while(!c[i])++i;
		anss=a[i];
		for(;i<=n;++i){
			if(c[i])anss&=a[i];
		}
		ans=max(ans,anss);
		return;
	}
	dfs(u+1,k);
	if(k>=m){
		return;
	}
	for(int i=1;i<=n;++i){
		if(!c[i]){
			c[i]=1;
			dfs(u+1,k+1);
			c[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0,ansss=(1<<30);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mx=max(mx,a[i]);
		ansss&=a[i];
	}
	if(m==1){
		cout<<mx;
		return 0;
	}else if(m==n){
		cout<<ansss;
		return 0;
	}else if(m==2&&n<=2000){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(n<=20){
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i){
		bool fl=1;
		int anss=0;
		for(int j=0;j<=30;++j){
			int b=((a[i]>>j)&1);
			cnt[j]+=b;
			if(b){
				if(!(i>=m&&cnt[j]>=m)){
					fl=0;
				}else{
					anss+=(1<<j);
				}
			}
		}
		ans=max(ans,anss);
//		if(fl){
//			cout<<a[i];
//			break;
//		}
	}
	cout<<ans;
	return 0;
}