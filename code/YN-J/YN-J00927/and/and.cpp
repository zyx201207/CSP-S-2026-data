#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
long long n,m,a[2005],mx=-1e8,p=-1e8;
priority_queue<int> q;
void dfs(int now,int num,int ans){
	if(num==m){mx=max(mx,ans);return;}
	for(int i=now+1;i<=n;i++){
		if(num==0)dfs(i,num+1,a[i]);
		else dfs(i,num+1,(a[i]&ans));
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	if(n>=20){
		int ans=a[1];
		if(m==1){
			cout<<q.top();

		}
		else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					mx=max(mx,a[i]&a[j]);
				}
			}
			cout<<mx;
		}
		else if(m==n){
			for(int i=1;i<=n;i++){
				ans=ans&a[i];
			}
			cout<<ans;
		}
	}
	else {
		dfs(0,0,-1);
			cout<<mx;
	}
	cout<<endl;
	return 0;
}
