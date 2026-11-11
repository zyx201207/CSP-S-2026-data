#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*====================*/
const int N=2e6+10;
/*====================*/
ll n,d,flag,ans;
ll x[N],G[N];
ll groups[N],cnt[N],cct;
queue<ll>q;
queue<ll>s;
	ll T=1,c;
/*====================*/
void Solve(void){
	ans=0;
	memset(G,0,sizeof G);
	memset(cnt,0,sizeof cnt);
	memset(groups,0,sizeof groups);
	cin>>n>>d;
	ll de=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(i==2)de=x[i]-x[i-1];
		else if(i>2&&x[i]-x[i-1]!=de){
			flag=1;
		}
	}
	//cout<<T<<"\n";
	if(!flag){
		
		//return;
	}
	ll j=1;
	for(int i=1;i<=n;i++){
		while(x[j+1]-x[i]<=d&&j<n)j++;
		G[i]=j;
		//cout<<G[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		if(G[i]==i)continue;
		if(G[i]-i>=2&&i<n-2){
			ll xx=x[G[i]],yy=x[G[i]-1];
			if(x[G[i]+1]-yy<=d){
				if(G[i]-i!=2)if(x[G[i]+1]-x[G[i]-2]<=d)continue;
				groups[i]=1;groups[G[i]+1]=1;
				ans++;
				//cout<<i<<" ";
			}
		}
		if(G[i]-i==1){
			q.push(i);
			if(i>2&&groups[i]&&x[i+1]-x[i-1]>d){
				ans++;
				//cout<<x[i+1]<<' '<<x[i-2]<<" "; 
				groups[i+1]=1;
			}
		}
	}
	while(!q.empty()){
		if(groups[q.front()-1]==1){
			ans++;
			groups[q.front()]=1;
			//cout<<q.front()<<" ";
		}
		q.pop();
	}
	cout<<ans<<"\n";
}
/*====================*/
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>c>>T;
	while(T--){
		Solve();
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
Oct31==Dec25?
*/
