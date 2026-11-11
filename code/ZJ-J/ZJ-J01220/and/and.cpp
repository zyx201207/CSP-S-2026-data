#include<bits/stdc++.h>
using namespace std;

int n,m,l,s[210000][40];
long long a[210000];

void solve(vector<int> q,int j){
	if(j==31){
		long long ans=a[q[0]];
		for(int i=0;i<m;i++){
			ans=ans&a[q[i]];
		}
		printf("%lld",ans);
		return ;
	}
	int x=0;
	vector<int> g;
	for(int i=0;i<q.size();i++){
		if(s[q[i]][j]==1){
			++x;
			g.push_back(q[i]);
		}
	}
	if(x==m){
		long long ans=a[g[0]];
		for(int i=0;i<m;i++){
			ans=ans&a[g[i]];
		}
		printf("%lld",ans);
		return ;
	}
	else{
		if(x<m){
			solve(q,j+1);
		}
		else{
			solve(g,j+1);
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(m==1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		printf("%lld",ans);
		return 0;
	}
	if(m==2&&n<=2000){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		int r=31;
		while(x!=0){
			s[i][--r]=x%2;
			x=x/2;
		}
	}
	vector<int> q;
	for(int i=1;i<=n;i++){
		q.push_back(i);
	}
	solve(q,1);
	return 0;
} 
