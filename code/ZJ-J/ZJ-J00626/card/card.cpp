#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[500005];
int cnt[300005];
int vis[300005];
bool vv[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]>a[i-1])f=0;
	}
	stack<int> s;
	if(f){
		for(int i=n;i>=1;i--){
			if(vis[a[i]]==0){
				cnt[a[i]]=i;
				vis[a[i]]=1;
			}
		}
	}else if(n<=5000){
		for(int j=1;j<=n;j++){
			for(int i=1;i<=m;i++)vis[i]=0;
			for(int i=j;i<=n;i++){
				if(vis[a[i]]==1){
					while(s.top()!=a[i]){
						vis[s.top()]=0;
						s.pop();
					}
				}else{
					vis[a[i]]=1;
					s.push(a[i]);
				}
			}
			while(!s.empty()){
				cnt[s.top()]++;
				s.pop();
			}
		}
	}else{
		for(int i=n;i>=1;i--){
			if(vis[a[i]]==0){
				s.push(i);
				vv[a[i]]=1;
				vis[a[i]]=i;
			}else{
				while(s.size()&&s.top()<vis[a[i]]){
					vv[a[s.top()]]=0;
					s.pop();
				}
				if(!vv[a[i]]){
					s.push(i);
					vv[a[i]]=1;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}