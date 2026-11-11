#include<bits/stdc++.h>
using namespace std;

const int N=1e6+7;
#define int long long
int c,t;
int n,k;
int u,v;
int dis,val[N],num=0;

void dfs(int arrival,int tim){
	//cout<<u<<" "<<arrival<<"tim:"<<tim<<endl;
	
	if(arrival==v&&tim==dis){
		num++;
	}
	if(tim>dis)return;
	if(arrival==v)return;
	for(int i=arrival+1;i<=v;i++){
		if(k>=(val[i]-val[arrival])){
			dfs(i,tim+1);
			
		}	
		
	}	
}

bool check(){
	int fly=k,cnt=1;
	for(int i=u+1;i<=v;i++){
		if(fly>=(val[i]-val[i-1])){
			fly-=(val[i]-val[i-1]);
		}else{
			if(val[i]-val[i-1]>k){
				return false;
			}
			cnt++;
			fly=k-val[i]+val[i-1];
		}
	}
	dis=cnt;
	//cout<<u<<" "<<v<<" "<<cnt<<endl<<endl;
	dfs(u,0);
	//cout<<"--->"<<num<<endl;
	return num==2;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>val[i];
		}
		if(c==1||c==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					u=i,v=j;
					if(check()){
						ans++;	
					}
					num=0;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}