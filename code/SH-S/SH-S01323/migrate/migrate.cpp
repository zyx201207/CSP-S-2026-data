#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,d,x[100010];
int dfs(int l,int r){
	if(l==r-1&&abs(x[r]-x[l])<=d){
		return 1;
	}
	else if(l==r-1) return 0;
	int cnt=0;
	for(int i=l+1;i<=r;i++){
		if(abs(x[i]-x[l])<=d){
			cnt+=dfs(i,r);
			if(cnt>2) return -1e9;
		}
	}
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T-->0){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				if(abs(x[r]-x[l])>(r-l)*d) continue;
				int s=dfs(l,r);
				//cout<<s<<endl;
				if(s==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
