#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int mx=0;
int n,m;
void dfs(int now,int sum,int xuan){
	if(now>n){
		if(xuan==m){
			mx=max(mx,sum);
		}
		return;
	}
	if(xuan<m){
		dfs(now+1,sum&a[now+1],xuan+1);
	}
	dfs(now+1,sum,xuan);
}
int main(){
	freopen("and.in","r",stdin); //!!!
	freopen("and.out","w",stdout); //!!!
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bool f2=0;
		for(int i=0;i<=31;i++){
			
			if((1LL<<i)-1==a[i]){
				f2=1;
			}
		}
		if(f2==0){
			f=0;
		}
	}
	if(n<=20){
		dfs(0,(1ll<<31)-1,0);
		cout<<mx;
	}else if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}else if(m==n){
		int ma=a[1];
		for(int i=2;i<=n;i++){
			ma&=a[i];
		}
		cout<<ma;
	}else if(m==2){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
	}else if(m==n-1){
		int ma=0;
		for(int i=1;i<=n;i++){
			int sum=(1LL<<31)-1;
			for(int j=1;j<=n;j++){
				if(j!=i){
					sum&=a[j];
				}
			}
			ma=max(ma,sum);
		}
		cout<<ma;
	}else if(f){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
	}
	return 0;
}