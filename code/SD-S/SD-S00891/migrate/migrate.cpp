#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int inf=LLONG_MAX;
const int maxn=5e5+5;
int c;
int n,d,cnt,cntmin;
int a[maxn],pre[maxn];
void dfs(int now,int to,int num){
	if(now==to){
		if(cntmin<num){
			return;
		}
		cnt++;
		cntmin=num;
		return;
	}
	int l=now,r=to; 
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]-a[now]<=d){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	for(int i=min(to,r);i>now;i--){
		dfs(i,to,num+1);
	}
	
}
int solve1(){
	a[0]=a[1];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[j-1]>d){
				break;
			}
			cnt=0,cntmin=inf;
			dfs(i,j,0);
			if(cnt==2){
				ans++;
			}
		}
	}
	return ans;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	cout<<solve1()<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;cin>>c>>T;
	while(T--) solve(); 
	return 0;
}

