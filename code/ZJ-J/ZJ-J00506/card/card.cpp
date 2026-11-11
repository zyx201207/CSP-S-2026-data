#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int mp[N];
int n,m;
int a[N];
int cnt[N];
int vis[N];
int sum[N];
int pos[N];
bool f=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) if(a[i]<a[i-1]) f=0;
	if(f){//16pts
		//a[1]<=a[2]<=...<=a[n]
		for(int i=n;i>=1;i--) if(!mp[a[i]]) mp[a[i]]=i;
		for(int i=1;i<=m;i++) cout<<mp[i]<<' ';
	}
	else if(n<=500&&m<=200){//24pts
		//1 2 3 1 2 3
		//- - - 1 2 3
		//  2 3 1 2 3
		//  - - - 2 3
		//    3 1 2 3
		//    - - - 3
		//      1 2 3
		//      1 2 3
		//        2 3
		//        2 3
		//          3
		//          3
		for(int i=1;i<=m;i++) mp[i]=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++) vis[j]=0;
			for(int j=i;j<=n;j++){
				if(mp[a[j]]!=-1){
					vis[mp[a[j]]]=1;
					vis[j]=-1;
					for(int k=mp[a[j]];k<=j-1;k++) mp[a[k]]=-1;
				}
				mp[a[j]]=j;
			}
			for(int j=i;j<=n;j++) sum[j]=sum[j-1]+vis[j];
			for(int j=i;j<=n;j++) if(!sum[j]) cnt[a[j]]++;
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	}
	else{//100pts
		//   3 1 2 1 3 2 3 1 2 1
		//1) 3 - - 1 3 2 3 1 2 1
		//2) - - - - 3 2 3 1 2 1
		//3) - - - - - - 3 1 2 1
		//4) - - - - - - 3 - - 1
		
		//   3 1 1 3 2 1 3
		//1) 3 - - 3 2 1 3
		//2) - - - 3 2 1 3
		//3) - - - - - - 3
		
		//   3 1 2 1 2 3 1 2 3 2 1
		//1) 3 - - 1 2 3 1 2 3 2 1
		//2) - - - - - 3 1 2 3 2 1
		//3) - - - - - - - - 3 2 1
		//可以直接找最远的a_i = a_j删除(?
		//每个相同的a_i可删除的最远距离相同(?
		for(int i=1;i<=n;i++) pos[a[i]]=i;
		for(int i=1;i<=n;i++){
			int now=i;
			while(now<=n){
				cnt[a[now]]++;
				now=pos[a[now]]+1;
			}
//			for(int i=1;i<=m;i++) cerr<<cnt[i]<<' ';
//			cerr<<'\n';
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	}
	return 0;
}
