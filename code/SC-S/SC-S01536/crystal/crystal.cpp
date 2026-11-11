#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long a[500005],ans;
bool vis[500005];
void dfs(long long x){
	if(x>n){
		long long cnt=0,fl,ct=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				cnt+=a[i];
				ct++;
				fl=a[i];
			}
		}
		if(fl*ct-cnt!=m){
			return;
		}
		ans=max(ans,ct);
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1);
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 