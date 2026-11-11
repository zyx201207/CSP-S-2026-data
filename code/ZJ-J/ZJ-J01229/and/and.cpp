#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],num[N],vis[N];
int n,m;
int cnt=0,mx=0;
void dfs(int x){
	if(cnt==m){
		int sum=num[1];
		for(int i=2;i<=cnt;i++){
			sum=(sum&num[i]);
		}
		mx=max(mx,sum);
		return;
	}
	for(int i=x;i<=n;i++){
		cnt++;
		num[cnt]=a[i];
		dfs(i+1);
		cnt--;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx;
	}
	else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
	}
	else if(m==n-1){
		for(int i=2;i<=n;i++){
			int sum=a[1];
			for(int j=2;j<=n;j++){
				if(j!=i) sum=(sum&a[j]);
			}
			mx=max(mx,sum);
		}
		int sum=a[2];
		for(int i=3;i<=n;i++){
			sum=(sum&a[i]);
		}
		mx=max(mx,sum);
		cout<<mx;
	}
	else if(n<=20&&m<=20){
		dfs(1);
		cout<<mx;
	}
	else{
		cout<<0;
	}
	return 0;
}