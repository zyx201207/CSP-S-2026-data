#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll num;
	ll takea;
	bool fin;
	bool operator<(node a)const{
		return takea > a.takea;
	}
};
ll c,n,m,d,q,w[500005],turn[501][501];
int fin[501][500005];
bool bel[501][500005];
vector<ll> tl[501];
ll v[2][500005][21],len[500005],anlis[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1 ;i <= m;i++) scanf("%lld",w + i);
	for(int i = 1;i <= n;i++){
		ll ls;
		scanf("%lld",&ls);
		for(int j = 0;j < ls;j ++){
			ll ls1,ls2;
			scanf("%lld%lld",&ls1,&ls2);
			fin[i][ls1] = len[ls1];
			//cout<<i<<ls1<<' '<<fin[i][ls1]<<endl;
			v[0][ls1][len[ls1]] = i;
			v[1][ls1][len[ls1]] = ls2;
			len[ls1]++;
			//cout<<v[1][ls1][j]<<' '<<ls2<<endl;
			bel[i][ls1] = 1;
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < len[i];j++){
			for(int z = j + 1; z < len[i];z++){
				tl[v[0][i][j]].push_back(v[0][i][z]);
				tl[v[0][i][z]].push_back(v[0][i][j]);
				if(turn[v[0][i][j]][v[0][i][z]] == 0){
					turn[v[0][i][j]][v[0][i][z]] = v[1][i][j] + v[1][i][z];
					turn[v[0][i][z]][v[0][i][j]] = v[1][i][j] + v[1][i][z];
				}
				else{
					turn[v[0][i][j]][v[0][i][z]] = min(turn[v[0][i][j]][v[0][i][z]],v[1][i][j] + v[1][i][z]);
					turn[v[0][i][z]][v[0][i][j]] = min(turn[v[0][i][z]][v[0][i][j]],v[1][i][j] + v[1][i][z]);
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
//		ll beg,tow,ans = 0;
//		scanf("%lld%lld",&beg,&tow);
//		ans = w[beg] + w[tow];
		priority_queue<node> qq;
//		for(int i = 0;i < len[beg];i++){
//			node ls1;
//			ls1.num = v[0][beg][i];
//			ls1.takea = v[1][beg][i];
//			ls1.fin = 0;
//			qq.push(ls1);
//		//	cout<<ans<<'*'<<endl;
//		}
		node ls1;
		ls1.num = i;
		ls1.fin = 0;
		ls1.takea = 0;
		qq.push(ls1);
		bool vis[501];
		memset(vis,0,sizeof(vis));
		while(!qq.empty()){
			node ls = qq.top();
			//cout<<ls.num<<' '<<ls.takea<<bel[ls.num][tow]<<endl;
			vis[ls.num] = 1;
			//if(i == 1999) cout<<i<<' '<<ls.takea<<endl;
			if(anlis[i][ls.num] == 0) anlis[i][ls.num] = ls.takea;
			else anlis[i][ls.num] = min(anlis[i][ls.num],ls.takea);
			qq.pop();
			for(int i = 0;i < tl[ls.num].size();i++){
				if(!vis[tl[ls.num][i]]){
					node lsto;
					lsto.fin = 0;
					lsto.num = tl[ls.num][i];
					lsto.takea = ls.takea + turn[ls.num][tl[ls.num][i]];
					qq.push(lsto);
				}
			}
		}
	}
	while(q--){
		ll beg,tow,ans = 0;
		scanf("%lld%lld",&beg,&tow);
		ans = v[1][tow][fin[v[0][beg][0]][tow]] + anlis[v[0][beg][0]][v[0][tow][0]] + v[1][beg][fin[v[0][beg][0]][beg]];
		for(int i = 0;i < len[beg];i++){
			for(int j = 0;j < len[tow];j++){
				ans = min(ans,v[1][tow][fin[v[0][tow][j]][tow]] + anlis[v[0][beg][i]][v[0][tow][j]] + v[1][beg][fin[v[0][beg][i]][beg]]);
			}
		}
		ans += w[beg] + w[tow];
		printf("%lld\n",ans);
	}
	return 0;
}
