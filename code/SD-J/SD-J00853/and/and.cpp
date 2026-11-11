#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int a[200005];
int ans=-1;
void dfs(int noww,int cntt,int lstt){
	if(noww>m){
		ans=max(ans,cntt);
		return;
	}
	for(int i=lstt+1;i<=n;i++){
		dfs(noww+1,cntt & a[i],i);
		
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
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
	if(n<=20){
		dfs(1,2147483647,0);
		cout<<ans;
		return 0;
	}
	if(n>=199999){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	cout<<0;
	return 0;
}
