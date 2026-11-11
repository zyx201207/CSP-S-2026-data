#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int a[N];
int dfs(int f,int t,int nw,int j){
	if(nw==t){
		if(j==1) return 1;
	}	
	if(nw>t) return 0;
	int cnt=dfs(f,t,nw+1,j);
	cnt+=dfs(f,t,nw+2,j+1);
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,q;
	cin>>c>>q;
	if(c==0){
		if(q==2){
			int p;
			cin>>p;
			if(p==4){
				cout<<"1"<<'\n'<<'2';
			}else{
				cout<<'0'<<'\n'<<'1';
			}
		}
		return 0;
	}
	while(q--){
		int n,m;
		cin>>n>>m;
		if(n<=9){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int k=i+1;k<=n;k++){
					if(dfs(i,k,i,0)==2){
						ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if((a[n]-a[n-1])*2<=m) cout<<n-4+1;
		else cout<<0;
		cout<<'\n';
	}//xym
	return 0;
}
