#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int cx[300005];
int ans[300005];
signed main(){
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag = 1;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])flag=  0;
	}
	if(flag){
		for(int i = 1;i<=n;i++){
			ans[a[i]]++;
		}
		for(int i = 1;i<=m;i++){
			ans[i]+=ans[i-1];
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i = 1;i<=n;i++){
		stack<int>s;
		for(int j = 1;j<=m;j++)cx[j] = 0;
		for(int j = i;j<=n;j++){
			if(!cx[a[j]]){
				cx[a[j]] = 1;
				s.push(a[j]);
			}else{
				while(s.size()&&s.top()!=a[j]){
					cx[s.top()] = 0;
					s.pop();
				}
				if(s.size()){
					cx[s.top()] = 0;
					s.pop();
				}
				s.push(a[j]);
				cx[a[j]] = 1;
			}
		}
		for(int j = 1;j<=m;j++){
			if(cx[j])ans[j]++;
		}
	}
	for(int i = 1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
/*
freopen("card4.in","r",stdin);
freopen("card.ans","w",stdout);
10 3
3 1 2 1 3 2 3 1 2 1

4 3
1 2 1 3
*/
