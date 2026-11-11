#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int sum[200005];
int qwq[200005];
bool cmp(int a,int b){
	return a>b;
}
int mx=0;
int ans=0;
void dfs(int x,int sum,int cnt){
	if(x>n){
		return;
	}
	if(cnt==m){
//		cout<<sum<<endl;
		ans=max(ans,sum);
		return;
	}
	if(cnt==0){
//		cout<<a[x]<<endl;
		dfs(x+1,a[x],1);
		dfs(x+1,0,0);
	}else{
		dfs(x+1,sum&a[x],cnt+1);
		dfs(x+1,sum,cnt);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n<=20){
		sort(a+1,a+1+n,cmp);
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}else if(n>20&&n<=2000){
		if(m==1){
			cout<<mx;
			return 0;
		}
		if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++){
				ans=ans&a[i];
			}
			cout<<ans;
			return 0;
		}
		if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						ans=max(ans,a[i]&a[j]);
					}
				}
			}
			cout<<ans;
			return 0;
		}
	}else{
		if(m==n-1){
//			for(int i=1;i<=n;i++){
//				if(i==1){
//					ans=max(ans,sum)
//				}
//			}
		}else if(mx<=4){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				qwq[a[i]]++;
			}
			if(qwq[4]>=m){
				cout<<4;
				return 0;
			}
		}else{
			sort(a+1,a+1+n,cmp);
			ans=a[1];
			for(int i=1;i<=m;i++){
				ans=ans&a[i];
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}

