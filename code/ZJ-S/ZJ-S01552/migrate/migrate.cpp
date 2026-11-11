#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,t,c,a[2000005];
namespace subtask_1{
	void main(){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int D=a[2]-a[1];
			if(d<=D){cout<<"0\n";continue;}
			int p=d/D;
			int len=p*2;
			cout<<max(n-len+1,0ll)<<"\n";
		}
	}
}
namespace subtask_2{
	int Ans,ans,sum;
	void dfs(int x,int y,int s){
		if(x==y){
			if(s<ans){
				ans=s;sum=1;
			}
			else if(s==ans)sum++;
			return;
		}
		for(int i=x+1;i<=y;i++){
			if(a[i]-a[x]<=d){
				dfs(i,y,s+1);
			}
		}
	}
	void main(){
		while(t--){
			Ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=INT_MAX,sum=0;
					dfs(i,j,0);
					if(sum==2){
						Ans++;
					}
				}
			}
			cout<<Ans<<"\n";
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		subtask_1::main();
	}
	else{
		subtask_2::main();
	}
	return 0;
}
