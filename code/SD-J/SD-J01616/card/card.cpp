#include <bits/stdc++.h>
using namespace std;
const long long MAXN=5e5,MAXM=3e5;
long long n,m,a[MAXN],ans[MAXM];
bool f[MAXM];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(ans,0,sizeof(ans));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		stack<long long> q;
		memset(f,false,sizeof(f));
		for(int i=k;i<=n;i++){
			if(f[a[i]]==true){
				while(1){
					long long to=q.top();
					q.pop();
					if(to==a[i]) break;
				}
			}q.push(a[i]);
			f[a[i]]=true;
		}while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}/*
1 2 1 3

1
*/
