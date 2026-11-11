#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7,M=3e5+7;
int n,m;
int a[N];
int cnt[M];
void solve(int x){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cnt[j]=0;
		stack<int>stk;
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]){
				while(!stk.empty()&&stk.top()!=a[j]) cnt[stk.top()]=0,stk.pop();
				if(!stk.empty()) stk.pop();
				stk.push(a[j]);
				cnt[a[j]]=1;
			}
			else{
				cnt[a[j]]=1;
			}
		}
		if(cnt[x]) ans++;
	}
	cout<<ans<<" "; 
	return ;
}
signed main(){
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) solve(i);
	return 0;
}
