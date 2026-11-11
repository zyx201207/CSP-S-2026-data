#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx,amaxx,ans,af[5];
bool vis[200005],f=1;
void dfs(long long p,long long i,long long sum){
	if(p==m){
		maxx=max(maxx,sum);
		return ;
	}
	if(i==n+1){
		return ;
	}
	dfs(p+1,i+1,sum&a[i]);
	dfs(p,i+1,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		amaxx=max(amaxx,a[i]);
		ans&=a[i];
		if(a[i]>=4){
			f=0;
		}
		if(f){
			af[a[i]]++;
		}
	}
	if(n<=20){
		dfs(0,1,2147483647);
		cout<<maxx<<" ";
		return 0;
	}
	if(m==1){
		cout<<amaxx;
		return 0;
	}else if(m==n){
		cout<<ans;
		return 0;
	}else if(f){
		if(af[3]<m){
			m-=af[3];
			if(af[2]<m){
				if(af[1]>=m){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<2;
				return 0;
			}
		}else{
			cout<<3;
			return 0;
		}
	}else if(m==2){
		long long amax=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				amax=max(amax,(a[i]&a[j]));
			}
		}
		cout<<amax;
		return 0;
	}
	return 0;
}
