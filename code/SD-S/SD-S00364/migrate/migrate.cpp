//20pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000009];
int n,d;
int tot;
int c[200009];
bool panduan(int pos){
	for(int i=2;i<=pos;i++){
		if(a[i]-a[i-1]>d) return false;
	}
	return true;
}
void dfs(int cnt,int x,int y,int pos){
	if(cnt==0) return ;
	if(cnt==1){
		if(pos==0) return ;
//		for(int i=1;i<=pos;i++) cout<<c[i]<<' ';
//		cout<<'\n';
		c[++pos]=y;
		if(panduan(cnt)) tot++;
		return ;
	}
	pos++;
	for(int i=x+1;i<y;i++){
		c[pos]=i;
		dfs(cnt-1,i,y,pos);
	}
}
bool check(int x,int y){
	int cnt=0;
	int nw=x;
	while(nw<y){
		int f=0;
		for(int i=y;i>=nw+1;i--){
			if(a[i]-a[nw]<=d){
				nw=i;
				cnt++;
				f=1;
				break;
			}
		}
		if(!f) break;
	}
	tot=0;
	dfs(cnt,x,y,0);
	//cout<<"test"<<tot<<'\n';
	if(tot==2) return true;
	return false;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c;
	cin>>c;
	if(c==1||c==2){
		int q;
		cin>>q;
		while(q--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(check(i,j)) ans++;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(c==11||c==12){
		int q;
		cin>>q;
		while(q--){
			cin>>n>>d;
			int r;
			for(int i=1;i<=n;i++) cin>>a[i];
			r=a[2]-a[1];
			if(d<2*r){
				cout<<0<<'\n';
				continue;
			}
			d/=r,d*=2;
			cout<<max(0ll,n-d+1)<<'\n';
		}
		return 0;
	}
	return 0;
}
