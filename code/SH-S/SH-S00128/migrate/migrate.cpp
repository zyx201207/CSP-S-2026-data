#include<bits/stdc++.h>
using namespace std;
long long t,c,d,a[2000005],ans=0,cnt=0,cn=0x3f3f3f3f,n;
void dfs(long long dq,long long e,long long p){
	if(dq==e){
		if(p<cn){
			p=cn;
			cnt=1;
		
		}
		else{
			cnt++;
		}
		return;
	}
	for(int i=dq;i<=min(dq+d,e);i++){
		dfs(i,e,p+1);
		
	}
}
int main(){
freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
int pd;
	for(int op=1;op<=t;op++){
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	
			for(long long i=1;i<=n;i++){
					
				for(long long j=i+1;j<=n;j++){
				pd=0;
					cnt=0;
				dfs(i,j,1);
			 
					if(cnt==2&&!pd){
						ans++;
						pd=1;
					}
				
				}
			
			
			cout<<ans<<'\n';
		}
	
	}
	
}
