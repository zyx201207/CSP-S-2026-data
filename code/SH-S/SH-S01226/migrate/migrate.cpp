#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,dst;
long long x[2000005],nxt[2000005];
long long dis(int s,int t){
	long long ans=0;
	int i=s;
	while(i<t){
		if(nxt[i]&&nxt[i]<=t){
			i=nxt[i];
			ans++;
		}
		else if(nxt[i]>t){
			ans++;
			break;
		}
	}
	return ans;
}
int dfs(int s,int t,int crd){
	if(s==t&&crd==dst) return 1;
	int ans=0;
	for(int i=s;x[i]-x[s]<=d&&i<=t;i++){
		ans+=dfs(i,t,crd+1);
	}
	return ans;
}
int main(){
	freopen("migrate1.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int rnd=1;rnd<=t;rnd++){
		cin>>n>>d;
		int pre=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			while(x[i]-x[pre]>d){
				nxt[pre]=i-1;
				pre++;
			}
		}
		while(pre<n){
			nxt[pre]=n;
			pre++;
		}
		long long ans=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				dst=dis(i,j);
				cout<<dst<<endl;
				if(dfs(i,j,0)==2) ans++;
				cout<<ans<<endl;
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}
