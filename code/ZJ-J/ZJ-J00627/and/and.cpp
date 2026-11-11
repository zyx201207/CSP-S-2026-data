#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],as=-1;
bool vis[200005]; 
void dfs_1(long long x){
	if(x==m+1){
		long long s;
		bool f=1;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				if(f){
					s=a[i];
					f=0;
				}else{
					s&=a[i];
				}
			}
		}
		as=max(as,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs_1(x+1);
		}
	}
}
void dfs_2(long long x){
	if(x==m+1){
		long long s;
		bool f=1;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				if(f){
					s=a[i];
					f=0;
				}else{
					s&=a[i];
				}
			}
		}
		as=max(as,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs_2(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=ceil(log2(a[i]));
		if(a[i]!=pow(2,k)-1){
			flag=0;
		}
	}
	bool f_1=1,f_2=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			f_1=0;
			break;
		}
	}
	if(f_1){
		cout<<a[1];
		return 0;
	}
	if(flag){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	} 
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		long long mx=-1;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					as=max(a[i]&a[j],as);
				}
			}
		}
		cout<<as;
		return 0;
	}
	if(m>n/2){
		m=n-m;
		dfs_1(1);
		cout<<as;
	}else{
		dfs_2(1);
		cout<<as;
	}
	return 0;
}
//dfs±©Á¦ 
