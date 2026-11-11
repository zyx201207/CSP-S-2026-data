#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
const long long M=2e18+5;
long long c,t;
long long n,d;
long long x[N];
long long ans=M,ans1;
void dfs(long long st,long long ar,long long bs){
	if(st==ar){
		ans=min(ans,bs);
		return;
	}
	for(long long i=st+1;i<=ar;i++){
		if(x[i]-x[st]<=d)
			dfs(i,ar,bs+1);
	}
	return;
}
void dfs2(long long st,long long ar,long long bs){
	if(st==ar){
		if(bs==ans)
			ans1++;
		return;
	}
	for(long long i=st+1;i<=ar;i++){
		if(x[i]-x[st]<=d)
			dfs2(i,ar,bs+1);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		long long ans2=0;
		for(long long i=1;i<n;i++){	
			for(long long j=i+1;j<=n;j++){
				ans=M;
				ans1=0;
				dfs(i,j,0);
				dfs2(i,j,0);
				if(ans1==2)
					ans2++;
			}
		}
		cout<<ans2<<endl;
	}
	return 0;
}