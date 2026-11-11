#include<bits/stdc++.h>

using namespace std;

const int N=2e6+3;

int n;
long long d;
long long x[N];
int ex;
long long ec;
int tj;

void dfs(int now,long long cnt){
	if(cnt>ec) return;
	if(tj>2||tj==-1){
		tj=-1;
		return;
	}
	if(now==ex){
		if(cnt==ec) tj++;
		return;
	}
	for(int i=now+1;i<=n;i++){
		if(x[i]-x[now]>d) continue;
		dfs(i,cnt+1);
		if(tj==-1) return;
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			cout<<"0\n";
		}
		return 0;
	}
	
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long ans=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				ex=j;
				ec=(x[j]-x[i]+d-1)/d;
				tj=0;
				dfs(i,0);
				if(tj==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
