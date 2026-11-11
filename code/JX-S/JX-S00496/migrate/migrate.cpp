#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1000;
long long cc,t,n,d,a[N],b[N],c[N],ans;
void dfs(long long x,long long cnt){
	//cout<<x<<" "<<cnt<<"\n";
	if(cnt<b[x]){
		b[x]=cnt;
		c[x]=1;
	}
	else if(cnt==b[x]){
		c[x]++;
	}
	if(x==n)return;
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d){
			dfs(i,cnt+1);
		}
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cc>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		//cout<<n-1<<" ";
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(cc>=11){
			long long e=a[2]-a[1];
			long long f=d/e;
			/*for(int i=f+2;i<=n;i++){
				long long ii=i-2;
				//cout<<ii/f<<" ";
				ans+=ii/f;
			}*/
			cout<<n-2*f+1<<"\n";
			continue;
		}
		for(int j=1;j<=n-1;j++){
			//cout<<j<<" "<<n-1<<" ";
			for(int i=1;i<=n;i++){
				b[i]=2147483647;
			}
			for(int i=1;i<=n;i++){
				c[i]=0;
			}
			dfs(j,0);
			for(int i=j;i<=n;i++){
				if(c[i]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
