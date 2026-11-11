#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans,times;
int a[N],vis[N];
vector<int> v[50];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],y=0;
		int len=0;
		while(x>0){
			y=(1<<len);
			if(x & y){
				v[len].push_back(i);
				x-=y;
			}
			len++;
		}
	}
	int pre=0;
	for(int i=30;i>=0;i--){
		int len=v[i].size();
		if(len>=m){
			if(pre==0){
				ans+=(1<<i);
				times++;
				pre=i;
				for(int j=0;j<len;j++){
					vis[v[i][j]]++;
				}
			}else{
				int cnt=0;
				vector<int> g;
				for(int j=0;j<len;j++){
					if(vis[v[i][j]]==times) cnt++,g.push_back(v[i][j]);
				}
				if(cnt>=m){
					ans+=(1<<i);
					pre=i;
					int t=0;
					for(int j=0;j<v[pre].size();j++){
						while(v[pre][j]>g[t]){
							t++;
						} 
						if(v[pre][j]==g[t]) vis[g[t]]++;
						
					}
					times++;
				}
			}
		}
	}
	cout<<ans;
	
	
	return 0;
}