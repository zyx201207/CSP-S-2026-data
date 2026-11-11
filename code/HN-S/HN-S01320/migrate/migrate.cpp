#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[2000006],n,d;int ans=1000000000,anscnt=0;
void dfs(int l,int r,int cnt){
	if(l==r){
		if(cnt<ans){
			ans=cnt;anscnt=1;
//			cout<<cnt<<" ";
		}
		if(cnt==ans&&ans!=1000000000)anscnt++;
	}
	for(int i=l+1;i<=r;i++){
		if(a[i]-a[l]<=d){
			dfs(i,r,cnt+1);
		}		
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;int anss=0 ;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=1000000000;anscnt=0;
				dfs(i,j,0);
//				cout<<anscnt<<" ";
				if(anscnt-1==2){
					anss++;
				}
			}
		}
		cout<<anss<<endl;
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2 
//1 2 3 4 5



