#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[200005],m=INT_MAX,mn=0,ans;
void dfs(int a1,int b1,int x){
//	cout<<1;
//	cout<<a1<<b1<<endl;
	if(x>d) return;
	if(a1==b1){
		if(x<m){
			m=x;
			mn=1;
			
		}
		else if(x==m){
			mn++;
			
		}
//		cout<<' '<<m<<endl;
		return ;
	}
	for(int i=a1+1;i<=b1;i++){
		if((a[i]-a[a1])<=d){
			dfs(i,b1,x+1);
		}
		else return;
	}
	
	return;
}
int main(){
	freopen("migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				m=INT_MAX;mn=0;
//				cout<<i<<' '<<j<<endl;
				dfs(i,j,1);
				if(mn==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
