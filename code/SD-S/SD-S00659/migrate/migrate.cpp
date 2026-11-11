#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n;
int ans1[N],ans2[N],ans;
long long d,a[N];
void dfs(int pos,int cnt){
//	cout<<pos<<" ";
	if(cnt<ans2[pos]){
		ans1[pos]=1;
		ans2[pos]=cnt;
	}
	else if(cnt==ans2[pos]){
		ans1[pos]++;
	}
	else return ;
	for(int k=pos+1;a[k]-a[pos]<=d&&k<=n;k++){
		dfs(k,cnt+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--&&cin>>n>>d){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			memset(ans1,0,sizeof ans1);
			memset(ans2,0x3f3f3f3f,sizeof ans2);
			dfs(i,1);
//			cout<<"\n";
//			for(int j=i+1;j<=n;j++){
//				cout<<i<<" "<<j<<":"<<ans2[j]<<"\n";
//			}
			for(int j=i+1;j<=n;j++){
				if(ans1[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

//CCF我恨你qwq，我和你不共戴天 
