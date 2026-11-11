#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[300005],ans[300005];
set<int>T;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		T.insert(a[i]);
	}
	if(T.size()==n){
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				ans[a[j]]++;
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		stack<int>s; 
		for(int k=i;k<=n;k++){
			if(b[a[k]]){
				while(s.size()&&s.top()!=a[k]){
					b[s.top()]=0;
					s.pop();
				}
				if(s.size())s.pop();
			}else b[a[k]]++;
			s.push(a[k]);
		}
		while(s.size()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}//11:50行了，干完了！！！ 

