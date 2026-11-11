#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2010042];
int cnt,max_cnt,max_way=0x3f3f3f3f;
void dfs(int x,int y,int ways){
	//if(cnt>2) return;
	if(x==y){
		if(ways<max_way){
			max_way=ways;
			cnt=1;
		}
		if(ways==max_way){
			cnt++;
		//	cout<<ways<<" ";
		}
		return;
	}
		for(int j=x+1;j<=y;j++){
			if(a[j]-a[x]<=d){
				dfs(j,y,ways+a[j]-a[x]);
			}
		}	
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}	
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				max_way=0x3f3f3f3f;
				dfs(i,j,0);
				if(cnt==2){
			 
					max_cnt++;
				}
			}
		}
		cout<<max_cnt<<"\n";
		max_cnt=0;
	}
}
