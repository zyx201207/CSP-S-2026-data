#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,x[N],ans,sl,i,j,minn; 
int dfs(int tp,int bs){
	if(tp==j){
		if(bs<minn){
			minn=bs,sl=1;
		}
		else sl++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++){
			if(x[i]==tp+j){
				dfs(tp+j,bs+1);
			}
		}
		
	}
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			minn=1e18,sl=0;
			dfs(i,0);
			if(sl==2)ans++;
		}
	}
	cout<<ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0; 
}


