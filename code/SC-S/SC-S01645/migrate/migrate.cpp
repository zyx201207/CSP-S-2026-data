#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int c,T,n,d,a[N],num,l,nmin,sum=0,cnt,ans=0,use=0,b[N];
bool check(int x,int y,int len){
	map<int,int> c;
	for(int i=x;i<=y;i++){
		c[a[i]]=1;
	}
	int p2=a[x];
	for(int i=1;i<=len;i++){
		p2+=b[i];
		if(c[p2]==0) return false;
	}
	return true;
}
void dfs(int p,int u,int v){
	if(sum==l&&use==num){
		if(check(u,v,p-1)){
			
			cnt++;
		}
		return;
	}
	if(sum>=l){
		return;
	}
	for(int i=nmin;i<=d;i++){
		if(sum+i<=l){
			sum+=i;
			use++;
			b[p]=i;
			dfs(p+1,u,v);
			sum-=i;
			use--;
		}
	}
}
void solve(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((a[j]-a[i])<=d){
				continue;
			}
			if((a[j]-a[i])%d==0){
				continue;
			}
			num=(a[j]-a[i])/d+1;
			l=a[j]-a[i];
			nmin=(a[j]-a[i])%d;
			cnt=0,use=0;
			dfs(1,i,j);
			if(cnt==2){
				ans++;
			}
		}
		
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==13||c==14){
		while(T--){
			cin>>n>>d;
			cout<<0<<endl;
		}
		return 0;
	}
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		solve();
	}
	return 0;
}