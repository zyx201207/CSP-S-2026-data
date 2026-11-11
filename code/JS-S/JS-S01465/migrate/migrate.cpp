#include<bits/stdc++.h>
using namespace std;
long long d;
long long a[10005];
int ton[100];
void dfs(int x,int y,int dep){
	if(x==y)ton[dep]++;
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d)
		dfs(i,y,dep+1);
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	if(c==1||c==2){
		int q;
		cin>>q;
		while(q--){
			long long n;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int i=1;i<=10;i++)ton[i]=0;
					dfs(i,j,0);
					int flag=0,ffl=0;
					for(int k=1;k<=15;k++){
						if(ton[k]==1||ton[k]>2)flag=1;
						if(ton[k]==2&&flag==0)ffl=1;
					}
					if(ffl==1)ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
