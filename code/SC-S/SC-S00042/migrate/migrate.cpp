#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,a[2000005],ans=0;
void dfs(int k,int nw,int len,int t){
	if(k>len) return;
	if(k==len&&nw==t){
		ans++;
		return;
	}
	for(int j=nw+1;j<=t;j++){
		if(a[j]-a[nw]<=d) dfs(k+1,a[j],len,t);
		else break;
	}
}
void solve(int s,int t){
	int len=1;
//	cout<<s<<" "<<t<<" "<<len<<"\n";
	for(int i=s;i<=t;i++){
		for(int j=i+1;j<=t;j++){
			if(a[j]-a[i]>d){
				len++;
				i=j-1;
				break;
			}
		}
	}
	ans=0;
	dfs(0,s,len,t);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				solve(a[i],a[j]);
				if(ans==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
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
*/