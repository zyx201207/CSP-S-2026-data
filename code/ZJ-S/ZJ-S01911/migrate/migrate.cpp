#include<bits/stdc++.h>
using namespace std;

int n,d;
long long x[200010];
int mn_num;
int mn_cnt;
long long zwt;

void dfs(int y,int z,int cnt){
	if(y==z){
		if(mn_num>cnt){
			mn_cnt=1;
			mn_num=cnt;
		}
		else if(mn_num==cnt){
			mn_cnt++;
		}
		return;
	}
	for(int i=y+1;i<=z;i++){
		if(x[i]-x[y]<=d){
			dfs(i,z,cnt+1);
		}
		else break;
	}
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		
		for(int i=2;i<=n;i++){
			mn_num=1e7;
			mn_cnt=0;
			dfs(1,i,0);
			if(mn_cnt==2) zwt++;
		}
		
		cout<<zwt<<"\n";
	}
	return 0;
}
