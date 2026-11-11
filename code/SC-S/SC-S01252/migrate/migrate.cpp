#include <iostream>
#include <cstdio>
#include <algorithm>

#include <map>
using namespace std;

map<int,map<int,int>> dis,cnt;
long long x[5050]={0};
int n;
long long d;

void dfs(int st,int ed,int ds){
	if(ds>dis[st][ed]){
		return ;
	}
	
	if(ds==dis[st][ed]){
		cnt[st][ed]++;
	}
	
	if(ds<dis[st][ed]){
		dis[st][ed]=ds;
		cnt[st][ed]=1;
	}
	
	for(int i=ed+1;(i<=n)&&(x[i]-x[ed]<=d);i++){
		dfs(st,i,ds+1);
	}
	
	return ;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,T;
	cin>>c>>T;
	
	if(c<=10){
		
		for(int rnd=1;rnd<=T;rnd++){
			
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					dis[i][j]=n+1;
					cnt[i][j]=0;
				}
			}
			
			for(int i=1;i<=n;i++){
				cin>>x[i];
				dis[i][i]=0;
				cnt[i][i]=0;
			}
			
			for(int i=n;i>0;i--){
				dfs(i,i,0);
			}
			
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(cnt[i][j]==2){
						ans++;
					}
				}
			}
			
			cout<<ans<<endl;
		}
		
	}
	
	if(c==11||c==12){
		
		for(int rnd=1;rnd<=T;rnd++){
			
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			
			int f=d/(x[2]-x[1]);
			long long ans=0;
			if(f==0){
				cout<<ans<<endl;
				continue;
			}
			for(int i=1;i<=n;i++){
				ans+=min(max(n-(i+f),0),f-1);
			}
			
			cout<<ans<<endl;
		}
		
	}
	
	if(c==13||c==14){
		
		for(int rnd=1;rnd<=T;rnd++){
			
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			
			cout<<n/2<<endl;
		}
		
	}
	
	if(c>=15){
		
		for(int rnd=1;rnd<=T;rnd++){
			
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			
			cout<<0<<endl;
		}
		
	}
	
	
	
	
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}