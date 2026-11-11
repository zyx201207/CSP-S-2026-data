#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans,mx;
void dfs(int p,int x,int sum){
	if(p==m+1){
		ans=max(ans,sum);
		return;
	}
	if(sum<=ans)return;
	for(int i=x;i+m-p<=n;i++){
		dfs(p+1,i+1,sum&a[i]);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n<=20){
		dfs(1,1,(1<<30)-1);
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n]<<endl;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++)ans&=a[i];
		cout<<ans<<endl;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(mx<4){
		ans=3;
		for(int i=n;i>=n-m+1;i--)ans&=a[i];
		cout<<ans<<endl;
		return 0;
	}
	bool f=true;
	for(int i=1;i<=n;i++){
		int x=log2(a[i]+1);
		if((int)pow(2,x)!=a[i]+1){
			f=false;
			break;
		}
	}
	if(f){
		ans=a[n];
		for(int i=n;i>=n-m+1;i--)ans&=a[i];
		cout<<ans<<endl;
		return 0;
	}
	f=true;
	int x=log2(n);
	if((int)pow(2,x)==n){
		for(int i=1;i<=n;i++){
			if(a[i]!=i-1){
				f=false;
				break;
			}
		}
		if(f){
			if(m>n/2)cout<<0<<endl;
			else{
				cout<<(int)pow(2,x-1)<<endl;
			}
			return 0;
		}
	}
	ans=a[n];
	for(int i=n;i>=n-m+1;i--){
		ans&=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
