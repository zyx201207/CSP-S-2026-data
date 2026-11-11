#include<bits/stdc++.h>
using namespace std;
const int maxn=5*2e6;
long long c,t,a[maxn],n,d,ans=0,s=0,ch[maxn];
void dfs(int x,int y,int b){
	if(x==y){
		ch[b]+=1;
	}
	for(int i=x+1;i<=y;i++){
		if(abs(a[i]-a[x])<=d){
			dfs(i,y,b+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(ch,0,sizeof(ch));
				dfs(i,j,0);
				for(int k=1;k<=maxn;k++){
					if(ch[k]!=0){
						if(ch[k]==2){
							ans++;
						}
						break;
					}
				}
			}
		}
		cout<<ans<<"\n"; 
	}
	
	return 0;
}
