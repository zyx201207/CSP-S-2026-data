#include<bits/stdc++.h>

using namespace std;
const int N=2e5+10;
int n,m,ans;
int a[N];
bool f[N];

void dfs(int x,int da){
	if(x==m+1){
		ans=max(ans,da);
		return ;
	} 
	int p=da;
	for(int i=1;i<=n;i++){
		if(!f[i]){
			if(x==1) p=a[i];
			else p&=a[i];
			f[i]=1;
			dfs(x+1,p);
			p=da;
			f[i]=0;
		}
	}
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>2000&&m!=4){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	
	return 0;
} 
