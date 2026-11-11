#include<bits/stdc++.h>
#define ll long long
using namespace std;
int yl,n,m,d,p;
int time[500070],ti[700][700],a[700][700];
void solve(int st,int en,int num){
	int minn;
	for(int i=1;i<=n;i++){
		if(ti[i][st]!=0){
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>yl>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>time[i];
	}
	for(int i=1;i<=n;i++){
		int nu;
		cin>>nu;
		for(int j=1;j<=nu;j++){
			int a,t;
			cin>>a>>t;
			ti[i][a]=t;
			a[a][i]=t;
		}
	}
	for(int i=1;i<=m;i++){
		if(n<=3){
			for(int j=1;j<=n;j++){
				
			}
		}
		
	}
	while(p--){
		int start,end;
		cin>>strat>>end;
		solve(start,end,0);
	}
	return 0;
}



