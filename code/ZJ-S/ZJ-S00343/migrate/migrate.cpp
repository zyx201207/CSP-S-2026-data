#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans;
long long X[2000005];
long long siz,Minst;
void dfs(int x,int en,int steps){
	if(x==en&&steps==Minst){
		siz++;
		return;
	}
	int right=x+1;
	while(d>=X[right]-X[x]){
		if(d<X[right]-X[x])break;
		if(right>en)break;
		dfs(right,en,steps+1);
		right++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>X[i];
		for(int sta=1;sta<n;sta++){
			for(int end=sta+1;end<=n;end++){
				siz=0;
				Minst=0;
				for(int k=sta+1;k<=end;k++)Minst+=X[k]-X[k-1];
				if(Minst%d==0)Minst/=d;
				else{
					Minst+=d;Minst/=d;
				}
				dfs(sta,end,0);
				if(siz==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}