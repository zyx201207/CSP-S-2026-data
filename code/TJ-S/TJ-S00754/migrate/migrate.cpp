#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const int N=5e3+5;
ll w[N];
int res,cnt;
int n;ll d;
void dfs(int s,int t,int len){
	if(cnt>2) return;
	if(s==t){
		if(len<res)
			res=len,cnt=1;
		else if(len==res)
			cnt++;
		return;
	}
	for(int j=s+1;j<=t&&w[j]-w[s]<=d;j++)
		dfs(j,t,len+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>w[i];
		int ans=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
				res=0x3f3f3f3f,cnt=0;
				dfs(i,j,0);
				if(cnt==2) ans++;
			}
		cout<<ans<<endl;
	}

	return 0;
}

