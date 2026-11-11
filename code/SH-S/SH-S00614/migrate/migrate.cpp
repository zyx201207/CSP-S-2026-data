#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=2e6+10; 
int a[N];
int n,d;
int min_=1e18+10,cnt=0;
void dfs(int x,int y,int tms){
	if(min_==2){
		//cout<<x<<endl;
	}
	if(x==y){
		//cout<<"a\n";
		if(tms<min_){
			min_=tms;
			cnt=1;
		}
		else if(tms==min_){
			
			cnt++;
		}
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d&&i<=y){
			//cout<<"aaa"<<x<<' '<<i<<' '<<tms<<' '<<y<<endl;
			
			
			dfs(i,y,tms+1);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int __,_;cin>>__>>_;
	while(_--){
		cin>>n>>d;
		memset(a,0,sizeof a);
		bool f=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3){
				if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
					f=0;
				}
			}
				
		}
		if(f){
			int k=max(a[2]-a[1],a[1]-a[2]);
			if(k*2>d){
				cout<<0<<endl;
				continue;
			}
			int aaa=(d/k)*2;
			cout<<max(0*d,n-aaa+1)<<endl;
		}
		else{
			if(n<4){
				cout<<0<<endl;
				continue;
			}
			int ans=0;
			for(int i=1;i<n-2;i++){
				for(int j=i+3;j<=n;j++){
					min_=1e18+10,cnt=0;
					dfs(i,j,0);
					//cout<<i<<' '<<j<<' '<<cnt<<' '<<min_<<endl;
					if(cnt==2){
						ans++;
						
					}
				}
			}
			cout<<ans<<endl;
		}
			
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 4
3 6 7 9 10 11
*/
