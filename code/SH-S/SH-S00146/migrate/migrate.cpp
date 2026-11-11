#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int a[N],sum=0,Min,n,d;
void dfs(int u,int cnt,int e){
	if(cnt>Min)return ;
	if(cnt==Min&&u==e){
		sum++;
		return ;
	}
	if(cnt<Min&&u==e){
		Min=cnt,sum=1;
		return ;
	}
	int q;
	for(q=u+1;q<=e;q++)if(a[q]-a[u]>d)break;
	q--;
	if(q==e)dfs(q,cnt+1,e);
	else for(;q>u;q--)dfs(q,cnt+1,e);
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	if(c==11||c==12){
		while(T--){
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			d=d/(a[2]-a[1]);
			if(d<=1||n-d-1<=0)
				cout<<0<<"\n";
			else cout<<n-2*d+1<<"\n";
		}
	}
	else if(c==13||c==14){
		while(T--){
			int ans=0,p;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(;p<=n;p++)if(a[p]-a[n]<=d&&a[n]-a[p]<=d)break;
			int r=1,l=1,k=1;
			for(int i=1;i<=n;i++){
				while(k<=n&&a[k]-a[i]<d)k++;
				while(r<=n&&a[r]-a[i]<2*d);
			}
		}
	}
	else if(c==1||c==2||c==0){
		while(T--){
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					Min=2e6+5,sum=0;
					dfs(i,0,j);
					if(sum==2)ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
