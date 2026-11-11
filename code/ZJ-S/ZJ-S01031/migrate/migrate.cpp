#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[1000000],ans;
int n,d; 
int f,mn;
void dfs(int l,int r,int ci){
	
	if(ci>mn)return ;
	if(l==r&&mn>ci){
		mn=ci;
		f=0;
	}
	if(l==r&&mn==ci){
		f++;
		return ;
	}
	//cout<<"l"<<l<<"r"<<r<<" "<<ci<<" "<<mn<<"\n";
	for(int i=1;i<=r-l;i++){
		if(x[l+i]-x[l]<=d)dfs(l+i,r,ci+1);
	}
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
    	ans=0;
		cin>>n>>d;
    	for(int i=1;i<=n;i++)cin>>x[i];
    	for(int l=1;l<=n;l++){
    		for(int r=l+1;r<=n;r++){
    			mn=n;
				dfs(l,r,1);
				if(f==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
   
}
