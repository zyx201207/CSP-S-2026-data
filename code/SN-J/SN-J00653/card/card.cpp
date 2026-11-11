//姜承宇 西安翱翔中学 SN-J00653
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum[300005],bj[500005],a[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	for(int i = 1;i<=n;i++){
		memset(bj,0,sizeof(bj));
		deque<int> q;
		for(int j = i;j<=n;j++){
			if(bj[a[j]] == 0){
				q.push_back(a[j]);
				bj[a[j]] = 1;
			}else{
				while(q.back()!=a[j]){
					bj[q.back()] = 0;
					q.pop_back();
				}
			}
		}
		while(q.size()!=0){
			if(bj[q.front()] == 1){
				sum[q.front()]++;
				bj[q.front()] = 0;
			}
			q.pop_front();
		}
	}
	for(int i = 1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}
