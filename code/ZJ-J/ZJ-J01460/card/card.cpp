#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
bool f[300010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    queue<int> q;
    stack<int> p;
    bool flag=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(i!=1 && a[i]<a[i-1]) flag=1;  
	}
	if(flag==0){
		for(int i=1;i<=n;i++){
			for(int j=n;j>=i;j--){
				ans[a[j]]++;
				if(a[j]==a[j-1]) break;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) q.push(a[j]);
		memset(f,0,sizeof f);
		while(!q.empty()){
			int ft=q.front();
			if(f[ft]==0){
				f[ft]=1;
				p.push(ft);
				q.pop();
			}
			else{
				while(!p.empty()){
					if(p.top()==ft) break;
					f[p.top()]=0;
					p.pop();
				}
				q.pop();
			}
		}
		while(!p.empty()){
			int tp=p.top();
			ans[tp]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
