#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;

int n,d;
int an[N];
int c,t;
int bn[N];
int sum;
int minn=1e9;
int num;

void dfs(int x,int y,int depth){
	if(x==y){
		if(depth<=minn){
			if(depth<minn){
				minn=depth;
				sum=1;
				//cout<<depth<<"\n";
			} else {
				sum++;
			}
		}
		//cout<<minn<<" "<<sum<<" "<<x<<" "<<y<<" "<<depth<<"\n";
		return ;
	}
	if(x>y) return ;
	for(int i=1;i<=d;i++){
		//if(an[x]+i!=an[x+1] || an[x]+i!=an[x+2]) continue;
		dfs(x+i,y,depth+1);
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		num=0;
		for(int i=1;i<=n;i++) cin>>an[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=0;minn=1e9;
				dfs(i,j,0);
				if(sum==2){
					num++;
					//cout<<i<<" "<<j<<"\n";
				}
			}
		}
		cout<<num<<"\n";
	}
	return 0;
}

