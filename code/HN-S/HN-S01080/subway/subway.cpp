#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,sj[50005],k,cf,js,tong[505][50005],zq,cnt,ans,op,kl;

int pq[505][50005],zpq[505][50005];
void dfs(int x){
	if(x==js&&kl==0){
		cout<<ans<<endl; 
		kl=1;
		return ;
	}

	for(int j=1;j<=n;j++){
		if(kl==1)return ;
		if(tong[j][x]=1){
			if(zpq[j][1]=x){
				ans+=pq[j][1];
				ans+=pq[j][2]; 
			
				op=zpq[j][2];
				if(op!=x)dfs(op);
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c!=0){
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>sj[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>zpq[i][j]>>pq[i][j];
			tong[i][zpq[i][j]]=1;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>cf>>js;
		ans=0;
		ans+=sj[cf];
		kl=0;
		for(int j=1;j<=n;j++){
			if(tong[j][cf]=1){
				ans+=pq[j][1];
				ans+=pq[j][2]; 
				op=zpq[j][2];
				dfs(op);
				
			}
		}
	} 

	return 0;
} 
