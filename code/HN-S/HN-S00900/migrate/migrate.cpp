#include<bits/stdc++.h>
using namespace std;
int n;
bool bian[5010][5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	
	cin>>c>>t;
	int n,d;
	while(t--){
		cin>>n>>d;
		vector<int>v(n+10);
		for(int i=1;i<=n;++i){
			cin>>v[i];
		}
		bool mb=false;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j)continue;
				if(abs(v[i]-v[j])<=d){
					bian[i][j]=true;
					mb=true;
				}
			}
		}
		if(mb){
			cout<<0;
			break;
		}
		
		
	}
	
	return 0;
}
 
