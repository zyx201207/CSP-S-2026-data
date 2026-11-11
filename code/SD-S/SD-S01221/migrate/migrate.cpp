#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,d;
int c,t;
int x[N],s[N];
void check(int x){
	
}
int f[N];
signed main(){
  	freopen("migrate.in","r",stdin);
  	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			s[i]=s[i-1]+x[i];
		}
		if(c>=11&&c<=12){
			int del=x[2]-x[1];
			int ans=0;
			for(int i=2;i<=d/del;i++){
				ans+=n-i+1;
			}
			cout<<ans<<"\n";
			continue;
		}
		memset(f,0x3f3f,sizeof(f));
		f[1]=0;
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			cnt=1;
			for(int j=1;j<i;j++){
				int sum=s[i]-s[j];
				int op=0;
				if(sum<=d) op=1;
				if(op&&f[i]>f[j]+1){
					f[i]=f[j]+1;
					cnt=1;
				}else if(f[i]==f[j]+1){
					cnt++;	
				}
			}
			ans+=cnt-1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
