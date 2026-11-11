#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long 
vector<int>vec;

int n,m;
int dfs(int step=1,int cnt=0,int sum=0xffffff){
	if(step>n){
		if(cnt==m)return sum;
		else return -1;
	}
	if(n-step+1<m-cnt)return -1;
	int ans=dfs(step+1,cnt,sum);
	if(cnt!=m){
		
	}ans=max(ans,dfs(step+1,cnt+1,sum&vec[step]));
	return ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	vec.resize(n+1);
	
	for(int i=1;i<=n;i++){
		cin>>vec[i];
	}
	if(m==1){
		cout<<*max_element(vec.begin()+1,vec.end())<<endl;
		return 0;
	}else if(m==n){
		int ans=vec[1];
		for(int i=2;i<=n;i++){
			ans&=vec[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	cout<<dfs()<<endl;
	return 0;
} 
