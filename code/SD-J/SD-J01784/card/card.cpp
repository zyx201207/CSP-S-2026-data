#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],ans[M];
bool f[N];
stack<int> s;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int t=1;t<=n;t++){
		memset(f,0,sizeof(f));
		for(int i=t;i<=n;i++){
			while(!s.empty()&&f[a[i]]){
				f[s.top()]=0;
				s.pop();
			}
			s.push(a[i]);
			f[a[i]]=1;
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
