#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans=1e18,k,a[2000005];
void dfs(long long s,long long e,long long cnt,long long sum){
	if(cnt==e){
		if(sum==ans){
			k++;
		}
		else if(sum>ans) return;
		else{
			k=1;
			ans=sum;
		}
		return;
	}
	if(a[e]-a[cnt]<=d){
		dfs(s,e,e,sum+1);
		return;
	}
	for(int i=cnt+1;i<=e;i++){
		if(a[i]-a[cnt]>d) break;
		dfs(s,e,i,sum+1);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			long long p=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					ans=1e18;
					k=0;
					dfs(i,j,i,0);
					if(k==2) p++;
				}
			}
			cout<<p<<endl;
		}
	}
	else if(c>=11&&c<=12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(a[2]-a[1]>d/2){
				cout<<0<<endl;
				continue;
			}
			long long x=d/(a[2]-a[1]);
			long long len=x+x-1;
			cout<<n-len<<endl;
		}
	}
	return 0;
}
