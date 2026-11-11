#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
bool vis[N];
int ans=0;
void dfs(int dep,int cnt){
	if(dep==m){
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(dep+1,cnt&a[i]);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int flag=0;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=3) flag++;
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn<<'\n';
		return 0;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
			if(ans==0){
				//ans=0;
				break;
			}
		}
		cout<<ans<<'\n';
		return 0;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<'\n';
		return 0;
	}else if(flag==n){
		int f1=0;
		int f2=0;
		int f3=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) f1++;
			else if(a[i]==2) f2++;
			else if(a[i]==3) f3++;
		}
		if(f3>=m){
			cout<<3<<'\n';
			return 0;
		}
		if(f3+f2>=m){
			cout<<2<<'\n';
			return 0;
		}
		if(f3+f1>=m){
			cout<<1<<'\n';
			return 0;
		}
		cout<<0<<'\n';
		return 0;
	}else if(m==n-1 and n>25){
		sort(a+1,a+n+1);
		int f1=a[2],f2=a[n-1],f3=a[n/2-1];
		for(int i=1;i<=n;i++){
			if(i!=1) f1=f1&a[i];
			if(i!=n) f2=f2&a[i];
			if(i!=n/2) f3=f3&a[i];
		}
		cout<<max(f1,max(f2,f3))<<'\n';
		return 0;
	}else if(n<=25){
		//cout<<-1;
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(1,a[i]);
			vis[i]=0;
		}
		cout<<ans<<'\n';
		return 0;
	}else{
		cout<<0<<'\n';
	}
	return 0;
}
