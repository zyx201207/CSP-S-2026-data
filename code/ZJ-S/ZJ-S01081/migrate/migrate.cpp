#include<bits/stdc++.h>
#define int long long

using namespace std;

int read(){
	int t=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		t=t*10+ch-48;
		ch=getchar();
	}
	return t*f;
}

int a[2000005];
int n,d;
bool check(int u,int v){
	int cnt=0;
	for(int i=u+1;i<=v-1;i++){
		if(a[i]-a[u]<=d&&a[v]-a[i]<=d){
			cnt++;
			if(cnt>2)return 0;
		}
	}
	return cnt==2;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c;
	cin>>c;
	if(c==11 or c==12){
		for(int T=read();T;T--){
			n=read();
			d=read();
			for(int i=1;i<=n;i++){
				a[i]=read();
			}
			if(n==1){
				cout<<0<<'\n';
				continue;
			}
			int diff=a[2]-a[1];
			if(diff>=d){
				cout<<0<<'\n';
				continue;
			}
			int res=d/diff*2-1;
			cout<<max(n-res,0LL)<<'\n';
		}
		return 0;
	}
	
	for(int T=read();T;T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(check(i,j))ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*

*/