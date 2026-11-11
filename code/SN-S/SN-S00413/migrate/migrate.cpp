#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,k,a[N],d[N],s[N];
void sol(){
	cin>>n>>k;for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j<=n;j++)d[j]=s[j]=0;s[i]=1;d[i]=0;
		for(int j=i+1,x=i;j<=n;j++){
			while(a[j]-a[x]>k)x++;if(x==j)break;
			int p=x;
			for(int o=1<<15;o;o>>=1)if(p+o<j && d[p+o]==d[x])p+=o;
			s[j]=s[j-1]+s[p]-s[x-1];d[j]=d[x]+1;
			if(s[p]-s[x-1]==2)ans++;
		}
	}cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int c,t;cin>>c>>t;while(t--)sol();
	return 0;
}

