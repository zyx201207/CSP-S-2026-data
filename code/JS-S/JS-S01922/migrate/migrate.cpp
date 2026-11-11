#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m;
int mp[305][305];
int a[5005];
struct node{
	int bian;
	int l;
};
int bfs(int f){
	queue<node>q;
	int sum=0;
	int num[5005][2]={};
	
	q.push({f,0});
	while(q.size()){
		node k=q.front();
		q.pop();
		if(num[k.bian][1]==0||num[k.bian][1]==k.l){
			num[k.bian][0]++;
			num[k.bian][1]=k.l;
		}
		else{
			continue;
		}
		
		for(int i=k.bian+1;i<=n;i++){
			if(mp[k.bian][i]==1){
				q.push({i,k.l+1});
				
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(num[i][0]==2){
			
			sum+=1;
	
		}
	}
	return sum;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		memset(mp,0x3f,sizeof mp);
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[j]-a[i]<=m){
					mp[i][j]=1;
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=bfs(i);
		}
		cout<<cnt<<endl;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
