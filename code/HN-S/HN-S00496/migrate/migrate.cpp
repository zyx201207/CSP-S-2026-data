#include<bits/stdc++.h>
using namespace std;

long long n,c,T,d,x[2000006],vis[2000005],dist[2000006];
long long aMin,sum,p;
long long y;

void dfs(long long w,long long cnt){
	if(w==y){
		if(aMin==cnt){
			sum++;
		}else if(aMin>cnt){
			sum=1;
			aMin=cnt;
		}
		return;
	}
	for(int i=w+1;i<=y;i++){
		if(abs(x[i]-x[w])<=d){
			dfs(i,cnt+1);
		}else{
			break;
		}
	}
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		vis[1]=1;
		for(int i=2;i<=n;i++){
			if(x[i]-x[i-1]<=d){
				vis[i]=1;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				aMin=1e9;
				sum=0;
				y=j;
				p=i;
				dfs(i,0);
				if(sum>=2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
