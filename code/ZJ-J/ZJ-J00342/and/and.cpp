#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=0;
	vector<int>a(n+1,0);
	vector<int>c(35,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		int x=a[i];
		int now=0;
		while(x){
			if(x&1)c[now]++;
			now++;
			x>>=1;
		}
	}
	int ans=0;
	bool fd=false;
	function<void(int,int)>dfs=[&](int num,int sum)->void{
		if(fd)return;
		if(num==-1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if((sum&a[i])==sum){
					cnt++;
					if(cnt==m)break;
				}
			}
			if(cnt==m){
				cout<<sum<<endl;
				fd=true;
			}
			return;
		}
		if(c[num]>=m)dfs(num-1,sum+(1<<num));
		dfs(num-1,sum);
	};
	dfs(31,0);
	return 0;
}
