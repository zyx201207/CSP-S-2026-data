#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
ll n,k,a[2000010],v[5010];
ll ans,sum,minn=2e9,cnt;
vector<ll> m[5010];
void dfs(ll x,ll y){
	//cout<<sum<<"\n";
	if(x==y){
		if(sum<minn){
			minn=sum;
			ans=0;
		}
		if(sum==minn){
			ans++;
		}
		return;
	}
	v[x]=1;
	for(ll i=0;i<m[x].size();i++){
		if(v[m[x][i]]==0){
			sum+=1;
			dfs(m[x][i],y);
			sum-=1;
		}
	}
	v[x]=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		memset(m,0,sizeof(m));
		cin>>n>>k;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			for(ll j=i-1;j>=1;j--){
				if(a[i]<=a[j]+k){
					m[i].push_back(j);
					m[j].push_back(i);
				}else{
					break;
				}
			}
	    }
	    for(ll i=1;i<=n;i++){
			for(ll j=i+2;j<=n;j++){
				ans=0,sum=0,minn=2e9;
				memset(v,0,sizeof(v));
				dfs(i,j);
				if(ans==2){
					cnt++;
				}
				//cout<<i<<"->"<<j<<"!!\n";
			}
		}
	    cout<<cnt<<"\n";
	}
}