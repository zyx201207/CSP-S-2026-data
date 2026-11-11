#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int xuan[N];int ans=0;
void dfs(int dep,int num){
	if(num==m){
		bool flag=0;int sum;
		for(int i=1;i<=n;i++){
			if(xuan[i]){
				if(!flag)sum=a[i];
				flag=1;
				sum&=a[i];
			}
		}
		ans=max(ans,sum);
	}
	if(dep>n){
		return ;
	}
	xuan[dep]=1;
	dfs(dep+1,num+1);
	xuan[dep]=0;
	dfs(dep+1,num);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int mx=0;
	int aand=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)aand=a[i];
		mx=max(mx,a[i]);
		aand&=a[i];
	}
	if(m==1){
		cout<<mx<<endl;
	}else if(m==n){
		cout<<aand<<endl;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			aand=a[i];
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,aand&a[j]);
			}
		}
		cout<<ans<<endl;
	}else if(n<=2000){
		dfs(1,0);
		cout<<ans<<endl;
	}else{
		sort(a+1,a+n+1); 
		int ans=a[n];
		for(int i=n;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans<<endl;
	} 
	return 0;
} 


