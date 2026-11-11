#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int c,n,t,ans;
ll d;
ll a[N];
int vis[N];
bool sol(int x,int y){
	memset(vis,0,sizeof vis);
	int sum=0;bool ok=false;
	vis[y]=vis[x]=1;
	for(int i=x;i<y;i++){
		if(a[i+1]-a[i]>d){
			return false;
		}
		while(a[i+1]-a[i]<=d){
			i++;if(i==y){
				sum++;break;
			}
		}
		vis[i]=1;
	}
	for(int i=y;i>x;i--){
		if(!vis[i])ok=true;
		if(a[i]-a[i-1]>d){
			return false;
		}
		while(a[i]-a[i-1]<=d){
			i--;if(i==x && ok){
				sum++;break;
			}
		}
	}
	return sum==2;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(sol(i,j))ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
