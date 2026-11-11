#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,q;
int a[N];
int lst[N];
int f[N];
vector<int> vt[N];
int ans=0;
int rd[N];
int res[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		lst[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		if(lst[a[i]]==i){
			vt[i].push_back(i+1);
			rd[i+1]++;
		}
		else{
			vt[i].push_back(lst[a[i]]+1);
			rd[lst[a[i]]+1]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=n+1;i++){
		if(rd[i]==0) q.push(i);
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(auto i:vt[now]){
			rd[i]--;
			f[i]+=f[now]+1;
			if(rd[i]==0) q.push(i);
		} 
		res[a[now]]+=f[now]+1;
	}
	for(int i=1;i<=m;i++) {
		if(i!=m) cout <<res[i]<<" ";
		else cout<<res[i];
	}
	return 0;
}

