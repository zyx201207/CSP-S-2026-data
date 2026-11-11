#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ans;
bool A=true;
int a[1000010];
void dfs(int now){
	if(now>n) return;
	if(m==0){
		ans=max(ans,cnt);
		return;
	}
	
	
	m--;
	if(cnt==0) cnt=a[now];
	else cnt=cnt & a[now];
	dfs(now+1);
	
	
	dfs(now+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((a[i]+1)%2!=0) A=false;
	}
	if(m==1) cout<<0;
	else if(m==n){
		for(int i=1;i<=n;i++){
			cout<<a[i];
		}
	}else if(A){
		sort(a+1,a+1+n);
		long long aaa=a[n-m+1];
		m--;
		while(m--){
			aaa=aaa & a[n-m+1];
		}
		cout<<aaa;
	}else{
		dfs(1);
		cout<<ans;
	}
	return 0;
	

}