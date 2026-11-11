#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<map>
#define ll long long
using namespace std;
int n,m,a[500010],ma,mi,x,ans;
bool ok;
void dfs(int x,int l,int s){
	if(s<=ans){
		return;
	}else if(x>m){
		ans=max(ans,s);
		return;
	}else{
		for(int i=l+1;i<=n;i++){
			dfs(x+1,i,s&a[i]);
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			mi=a[i];
		}
		ma=max(a[i],ma);
		mi=min(a[i],mi);
	}
	if(n==m){
		cout<<mi;
	}else if(m==1){
		cout<<ma;
	}else{
		ok=1;
		for(int i=1;i<=n;i++){
			x=1;
			while(x<=a[i]){
				x*=2;
			}
			if(x!=a[i]+1){
				ok=0;
				break;
			}
		}
		if(ok==1){
			sort(a+1,a+n+1);
			cout<<a[m];
		}else{
			for(int i=1;i<=n;i++){
				dfs(1,i,a[i]);
			}
			cout<<ans;
		}
	}
	return 0;
}