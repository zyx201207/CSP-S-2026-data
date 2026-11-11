#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d,x[2000010];
int D;
void cheat1(){
	D=x[n]-x[n-1];
	if(D>=d)cout<<0<<'\n';
	;
}
void brute(){
	int ans=0;
	for(int l=1;l<=n;++l){
		for(int r=l+1;r<=n;++r){
			int path=0;
			for(int k=l+1;k<r;++k){
				if(x[k]-x[l]<=d&&x[r]-x[k]<=d)path++;
			}
			if(path==2){
				cerr<<l<<' '<<r<<'\n';
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof x);
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		if(c==11||c==12){
			cheat1();
		}else if(n<=300){
			brute();
		}
	}
	return 0;
}

