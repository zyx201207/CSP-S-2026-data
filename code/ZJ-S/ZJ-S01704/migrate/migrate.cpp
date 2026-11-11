#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,a[200001],m;
int b[200001];
int mi;
int dfs(int x,int y,int z,int t){
	if(z==y){
		return 1;
	}
	if(t>=mi){
		return 0;
	}
	int ans=0;
	if(b[z]>y)return 1;
	for(int i=b[z];i>=z+1;i--){
		int df=dfs(x,y,i,t+1);
		if(df==0)break;
		ans+=df;
		if(ans>2)return ans;
	}	
	return ans;
}
bool is(int x,int y){
	int i=x;
	mi=0;
	while(i<y){mi++;if(a[i+1]-a[i]>m)return false;i=b[i];}
	return dfs(x,y,x,0)==2;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		int y=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			while(a[i]-a[y]>m)b[y++]=i-1;
			b[i]=n;
		}
		int answer=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(is(i,j)){
					answer++;
				}
			}
		}
		cout<<answer<<endl;
	}
	return 0;
}
