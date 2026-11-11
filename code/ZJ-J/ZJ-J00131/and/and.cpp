#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,cnt=1;
void dfs(int x,int s,int sum){
	if(x==m){
		ans=max(sum,ans);
		return;
	}
	if(s>n) return;
	dfs(x+1,s+1,sum&a[s]);
	dfs(x,s+1,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
	}
	else if(m==2){
		int mx=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}
	else if(n<=20){
		dfs(0,1,1073741823);
		cout<<ans;
	}
	else{
		cout<<"0";
	} 
	return 0;
}
