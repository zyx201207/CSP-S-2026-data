#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005],ans;
int get_low(int u,int v){
	int lstnow=INT_MIN,now=a[u],ret=0,i=u;
	while(now<a[v]&&now!=lstnow){
		ret++;
		lstnow=now;
		now+=d;
		while(a[i+1]<=now&&i+1<=n){
			i++;
		}
		now=a[i];
	}
	return ret;
}
int solve(int u,int v,int mb,int now){
	if(a[u]+(mb-now)*d<a[v]){
		return 0;
	}
	if(u>v){
		return 0;
	}
	if(now==mb&&u==v){
		return 1;
	}
	if(now==mb){
		return 0;
	}
	int ret=0;
	for(int i=1;;i++){
		if(u+i>n||a[u+i]>a[u]+d){
			break;
		}else{
			ret+=solve(u+i,v,mb,now+1);
		}
	}
	return ret;
}
signed main(){
	// maybe 40 pts
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int tmp=get_low(i,j);
				if(tmp>=2&&solve(i,j,tmp,0)==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}