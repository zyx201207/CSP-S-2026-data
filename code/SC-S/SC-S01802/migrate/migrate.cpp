#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e6+10;
typedef long long ll;
ll c,T,n,d,ans,res,t,cnt;
ll a[N],dc[N];
void dfs(int s,int e,int res,ll sum){
	if(res>t)return;
	if(s==e+1){
		if(res<t)cerr<<"NOOOOO!";
		++cnt;
		return;
	}
	if(sum+dc[s]<=d){
		dfs(s+1,e,res,sum+dc[s]);
		dfs(s+1,e,res+1,dc[s]);
	} else dfs(s+1,e,res+1,dc[s]);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],dc[i-1]=a[i]-a[i-1];
		for(int i=1;i<n;i++){
			if(dc[i]>d)continue;
			for(int j=i;j<n;j++){
				if(dc[j]>d)break;
				t=1,cnt=0;
				for(ll k=i,sum=0;k<=j;k++){
					sum+=dc[k];
					if(sum>d)sum=dc[k],++t;
				}
				dfs(i,j,1,0);
				if(cnt==2)++ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}