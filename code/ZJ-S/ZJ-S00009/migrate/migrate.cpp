#include<bits/stdc++.h>
using namespace std;
int n,d;
vector<int> x(200086);
int cnt=0,minn=0x3f;
void dfs(int a,int b,int len){
	if(a==b){
		if(len==minn) cnt++;
		else if(len<minn){
			cnt=1;
			minn=len;
		}
		return;
	}
	int nxt=a+1;
	while(nxt<=b && x[nxt]-x[a]<=d){
		dfs(nxt,b,len+1);
		nxt++;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>x[i];
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				cnt=0;
				minn=0x3f;
				dfs(i,j,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
