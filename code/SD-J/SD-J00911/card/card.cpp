#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],l[maxn],ll[maxn],lk[maxn],ans[maxn],b[maxn];
signed main(){
	//此处应有注释 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(l[a[i]]!=0){
			lk[l[a[i]]]=i;
			ll[i]=l[a[i]];
			l[a[i]]=0;
		}
		else l[a[i]]=i;
	}
	priority_queue<int>q;
	while(!q.empty())q.pop();
	for(int i=n;i>=1;i--){
		while(!q.empty()&&q.top()>=i)q.pop();
		if(lk[i]!=0)q.push(lk[i]);
		if(q.empty())ans[a[i]]+=i;
		else ans[a[i]]+=i-q.top();
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
/*
rp++
可惜了，写不完了
AK失败了 
CCF会看到这里吗 
*/

















/*
【鸽子衔枝之年】
天上 
*/
