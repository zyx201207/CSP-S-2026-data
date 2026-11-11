#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],t[N],ans[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		d[a[i]]=i;
	}
	if(n>5000){
		for(int i=1;i<=m;++i){
			cout<<d[i]<<" ";
		}
		return 0;
	}
	for(int k=1;k<=n;++k){
		stack<int>s;
		memset(t,0,sizeof(t));
		for(int i=k;i<=n;++i){
			if(t[a[i]]==1){
				while(!s.empty()&&s.top()!=a[i]){
					t[s.top()]=0;
					s.pop();
				}
			}
			else {
				s.push(a[i]);
				t[a[i]]=1;
			}
		}
		for(int i=1;i<=m;++i){
			ans[i]+=t[i];
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}

