#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],flag[300005],cnt[300005],pre=1;
queue<long long> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	while(pre<=n){
		for(long long i=pre;i<=n;i++){
			if(!flag[a[i]]){
				q.push(a[i]);
				flag[a[i]]=1;
			}
			else{
				while(!q.empty()){
					q.pop();
				}
				q.push(a[i]);
			}
		}
		while(!q.empty()){
			long long xx=q.front();
			cnt[xx]++;
			q.pop();
		}
		memset(flag,0,sizeof flag);
		pre++;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
//ccf rangwozuolao zuinieshenzhong yuyijixing lijizhixing (gunmu)
//ccf nikezhizui??
