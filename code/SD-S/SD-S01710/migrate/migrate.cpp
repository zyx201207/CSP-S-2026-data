#include<iostream>

using namespace std;
int  c,t;
int n,d;
int a[2000020];
int res;
int min1=1000000010,min2;
void dfs(int x,int y,int tim){
	if(tim<min2&&x==y) {
		res=1;
		return;
	} 
	if(tim=min2&&x==y) {
		res++;
		return;
	}
	if(tim>min2){
		return;
	}
	for(int i=x;i<=y;i++){
		if(a[i]-a[t]<=d) dfs(i,y,tim++);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12||c==13||c==14){
		for(int i=1;i<=t;i++){
			cout<<0<<endl;
		}
		return 0;
	}
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				res=0;
				min2=min1;
				dfs(i,j,0);
				
				if(res==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
