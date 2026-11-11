#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005],ans[300005];
priority_queue<int> pq[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
		pq[a[i]].push(i);
	}
	for(int i = 1;i<=n;i++){
		for(int k = 1;k<=m;k++){
			while(pq[k].top()<i&&pq[k].empty()){
				pq[k].pop();
			}
		}
		int flag = 1;
		int j = i;
		while(flag){
			while(!(pq[j].size()>1)&&j<=n){
				j++;
			}
			if(j>=n)break;
			int k = pq[j].top();
			pq[j].pop();
			k = pq[j].top();
			pq[j].push(k);
		}
		for(int k = 1;k<=m;k++){
			ans[k]+=pq[k].size();
		}
	}
	for(int i = 1;i<=m;i++){
		printf("%d",ans[i]);
	}
	return 0;
}
