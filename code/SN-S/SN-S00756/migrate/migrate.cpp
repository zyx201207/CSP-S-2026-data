#include<bits/stdc++.h>
using namespace std;
long long x[2000005],n,d,v[2000005],cnt[2000005];
void dfs(int a,long long z){
	for(int i=a+1;i<=n;i++){
		if(x[i]<=x[a]+d){
			z++;
			dfs(i,z);
			z--;
		}
		else break;
	}
	if(v[a]>z){
		v[a]=z;
		cnt[a]=1;
	}
	else if(v[a]==z)cnt[a]++;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==13||c==14){
			int sq=x[2]-x[1],p=0;
			for(int i=3;i<=n;i++){
				if(x[i]-x[i-1]!=sq){
					p=1;
					break;
				}
			}
			if(p==0){
				if(2*sq>d||3*sq<=d)cout<<0<<"/n";
				else if(d>=2*sq){
					if(n>3)cout<<n-3<<"/n";
				}
				continue;
			}
		}
		for(int i=1;i<n-d;i++){
			memset(v,0x3f,sizeof(v));
			memset(cnt,1,sizeof(cnt));
			dfs(i,0);
			for(int i=1;i<=n;i++){
				if(cnt[i]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
