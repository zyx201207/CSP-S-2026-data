#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long x[2000005];
long long ans,mn,total;
void dfs(int now,int end,int path){
	if(path>mn){
		return ;
	}
	if(now==end){
		if(mn==path){
			total++;
		}
		if(path<mn){
			total=1;
			mn=path;
		}
		return ;
	}
	for(register int i=end;i>now;i--){
		if(x[i]-x[now]<=d){
			if(path+1>mn){
				break;
			}
			dfs(i,end,path+1);
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=0&&c<=10){
		while(t--){
			ans=0;
			scanf("%d%lld",&n,&d);
			for(register int i=1;i<=n;i++){
				scanf("%lld",&x[i]);
			}	
			for(register int i=1;i<=n;i++){
				for(register int j=i+3;j<=n;j++){
					if(x[j]-x[i]<=d){
						continue;
					}
					mn=2000005;
					total=1;
					dfs(i,j,0);
					if(total==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}else if(c==11||c==12){
		while(t--){
			ans=0;
			scanf("%d%lld",&n,&d);
			for(register int i=1;i<=n;i++){
				scanf("%lld",&x[i]);
			}
			int duanshu=d/(x[2]-x[1]);
			for(register int i=1;i<=n;i++){
				if((n-i+1)/duanshu-1==0){
					break;
				}
				ans=ans+((n-i+1)/duanshu-1);
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
