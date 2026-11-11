#include<bits/stdc++.h>
using namespace std;
struct node{
	int k,l,o;
}a[100000]; 
int w[10000];
int y2[5]={0,0,-1,1};
int x1[5]={1,-1,0,0};

int ans=0;
int cnt=-10000;
bool f[1000][1000];
void dfs(int x,int y,int arr){
	if(y==arr){
		cout<<cnt<<endl;
		return;
	}
	ans=0;
	
	bool f1[1000][1000];

	
	for(int j=0;j<4;j++){
		
		x=x+x1[j];
		y=y+y2[j];
		if(f[x][y]==0){
			continue; 
		}
		else{
			if(f1[x][y]==1){
				continue;
			}
			else{
				ans=ans+f[x][y];
				f1[x][y]==1;
				f1[y][x]==1;
				dfs(x,y,arr);
			}
			
		}
		cnt=max(cnt,ans);
		
	}
	cout<<cnt<<endl;
} 

	

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k1;
		cin>>k1;
		for(int j=1;j<=k1;j++){
			cin>>a[j].k>>a[j].l;
			f[a[j].k][a[j-1].k]=a[i].l;
			f[a[j-1].k][a[j].k]=a[i].l;
		}
	}
	
	while(q--){
		int ppp,arr;
		cin>>ppp>>arr;
		dfs(ppp,1,arr);
		//cout<<cnt<<endl;
	}
	return 0;
}

