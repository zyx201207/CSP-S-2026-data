#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[210000],b[210000],ma,sum,n,ans,m,aans;
void dfs(int st,int cnt){
	if(cnt==m+1){
			for(int i=1;i<=m;i++){
				if(i==1)ans=b[i];
				else ans=ans&b[i];
				
			}	
			aans=max(aans,ans);
			//cout<<" "<<b[1]<<" "<<b[2]<<" "<<ans<<endl;cout<<endl;
			return;
	}
	if(st==n+1){
		
		
		return;
		
		
	}
	for(int i=st;i<=n;i++){
		
		b[cnt]=a[i];
		dfs(i+1,cnt+1);
		b[cnt]=0;
//		dfs(st+1,cnt);
//		b[cnt]=0;
	} 
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		if(i==1){
			sum=a[i];
			
		}
		else sum=sum&a[i];
	} 
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	dfs(1,1);
	
	cout<<aans;
	return 0;
}

