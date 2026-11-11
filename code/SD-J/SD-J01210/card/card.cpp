#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int ans[500010];
bool f[500010];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]] == 0){
				f[a[j]] = 1;
				s.push(a[j]);
			}
			else{
				while(!s.empty()){
					if(s.top() == a[j]) break;
					f[s.top()] = 0;
					s.pop();
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(f[i]) ans[i] ++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
