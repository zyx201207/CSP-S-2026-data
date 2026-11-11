#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int stk[M],top;
int a[M],ans[M],cnt[M];
bool f[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]&&flag)flag=false;
	}
	if(flag){
		for(int i=1;i<=n;i++)cnt[a[i]]=i;
		for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)f[a[j]]=false;
		stack<int>s;
		for(int j=i;j<=n;j++){
			if(!f[a[j]]){
				f[a[j]]=true;
				s.push(a[j]);
			}else{
				while(s.top()!=a[j]){
					f[s.top()]=false;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
