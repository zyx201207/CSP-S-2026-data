#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int v[200005],t[33],l[200005];
int n,m,ans=-1;
set <int> ss[33];
void dfs(int now,int nn){
	if(now==-1){
		for(int i=1;i<=n;i++){
			if(l[i]==1) ans=ans&v[i];
		}
		return ;
	}
	int j=(t[now]>=m);
	if(j==1){
		for(int i=1;i<=n;i++) if((!ss[now].count(v[i]))){
			l[i]=0;
			int ccc=v[i],cc=0;
			while(ccc){
				if(ccc%2==1) t[cc]--;
				cc++;
				ccc/=2;
			}
		}
		nn=t[now];
	}
	dfs(now-1,nn);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		cnt=0;
		int ccc=v[i];
		while(ccc){
			if(ccc%2==1) t[cnt]++,ss[cnt].insert(v[i]);
			cnt++;
			ccc/=2;
		}
		l[i]=1;
	}
	dfs(33,n);
	for(int i=1;i<=n;i++){
		if(l[i]==1) {
			if(ans==-1) ans=v[i];
			ans&=v[i];
		}
	}
	cout<<ans;
	return 0;//×¢ÊÍ 5 3 31 3 1 15 7
} 
