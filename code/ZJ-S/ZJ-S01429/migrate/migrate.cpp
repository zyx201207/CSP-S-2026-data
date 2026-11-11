#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x,a[2000001],f[2000001],ans1,ans2,ans;
bool ff;
void dfs(long long x,long long s,long long j){
	if(x>=j){
		if(s==ans1){
			ans2++;
			return;
		}
		else if(s<ans1){
			ans1=s;
			ans2=1;
		}
	}
	for(int i=1;i<=j;i++)
		if(a[i]-a[x]<=d&&f[i]==0){
			f[i]=1;
		    dfs(i,s+1,j);
		    f[i]=0;
		}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>a[i];
		ans=0;
		ff=0;
		for(int i=2;i<n;i++)
		    if(a[i]-a[i-1]!=a[i+1]-a[i]){
		    	ff=1;
		    	break;
		    }
		if(ff==0){
			long long x=a[2]-a[1],ss;
			for(int i=1;;i++)
				if(d<x*i){
					ss=i-1;
					break;
				}
			if(d<2)cout<<"0\n";
			else cout<<max(0ll,n-2*d+1);
			continue;
		}
		for(long long i=1;i<n;i++)
		    for(int j=i;j<=n;j++){
		    	ans1=INT_MAX;
		    	ans2=0;
		    	f[i]=1;
		    	dfs(i,0,j);
		    	f[i]=0;
		    	if(ans2==2)ans++;
			}
		cout<<ans<<"\n";
	}
}