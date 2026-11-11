#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
#define N 1000002
int n,d;
int a[N];
bool if_a;
int maxx[10][10];
int check(int x,int y,int cnt){
	int ans=0;
	if(x>y) return 0;
	if(x==y){
		if(cnt<maxx[x][y]){
			maxx[x][y]=cnt;
			return -4;
		}else if(cnt==maxx[x][y]) return 1;
		
	}int pos=0;
	for(int i=x+1;i<=n;i++){
		if(a[x]+d<a[i]) break;
		int g=check(i,y,cnt+1);ans+=g;
		if(g==-1){
			ans=-1;
			break;
		}
		if(g==-4){
			ans=1;
		}
	}
	return ans;
}
void solve2(){
	int ans=0;
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++) maxx[i][j]=INT_MAX;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(i,j,0)==2){
				ans++;
//				cout<<i<<' '<<j<<'\n';
			}
		}
	}
	cout<<ans<<'\n';
}
void solve(){
	cin>>n>>d;
	if(n<3){
		cout<<0<<'\n';
		return;
	}
	if(n<=9){
		solve2();return;
	} 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&((a[i]-a[i-1])!=(a[2]-a[1]))) if_a=1;
	}
	
	if(!if_a){
		int cha=a[2]-a[1];
		if(d<cha){
			cout<<"0\n";
			return;
		}
		if(d<2*cha){
			cout<<0<<'\n';
			return;
		}
		cout<<((n-1)/(cha/d))+1<<'\n';
	}else cout<<"0\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++) solve();
	return 0;
}
