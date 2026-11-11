#include<bits/stdc++.h>
using namespace std;
// #define int long long
constexpr bool online=1;
int c,t,n,m,ans;
vector<int>son[4005];
vector<pair<int,int>>es;
int cl,cr; bool cur[4005],lf[4005];
vector<int>cv[2];
inline void coll(int p,int f){
	if(son[p].size()-cur[p]<=1) lf[p]=1;
	for(int sp:son[p]) if(sp!=f) coll(sp,p);
}
struct mxv{
	int v1,v2,vp;
	inline void set(){
		vp=v1=v2=0;
	}
	inline void ins(int v,int p){
		if(v>=v1) v2=v1,v1=v,vp=p;
		else v2=max(v2,v);
	}
}mx[4005];
inline int dfs(int p,int f){
	mx[p].set();
	for(int sp:son[p]) if(sp!=f)
		mx[p].ins(dfs(sp,p)+1,sp);
	return mx[p].v1;
}
inline void dfc(int p,int f,int v){
	mx[p].ins(v,f);
	if(lf[p]) mx[p].set();
	cv[0].emplace_back(mx[p].v2);
	for(int sp:son[p]) if(sp!=f)
		if(sp==mx[p].vp) dfc(sp,p,mx[p].v2+1);
		else dfc(sp,p,mx[p].v1+1);
}
signed main(){
	if(online)
		freopen("hub.in","r",stdin),
		freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	/*
	考虑钦定最终每一个城市被哪一边管
	总可以断掉一条边，然后左右分别管

	随后进行二分答案，所有的叶子节点向中间缩距离
	看看缩完剩下多少个节点即可

	也就是说我需要维护这样的东西：
	断掉一条边之后，每一个节点的次远叶子节点距离多少
	特别的叶子节点视为 0
	这个数值就是一个节点被缩掉的时间

	左右两边分别收集结果，排序之后双指针一下就知道了
	时间复杂度为 O(n^2\log n)，3s 应该能跑，有 50pts
	*/
	for(cin>>c>>t;t;t--){
		cin>>n>>m; es.clear(); ans=1e9;
		for(int i=1;i<=n;++i) son[i].clear();
		for(int i=1,l,r;i!=n;++i)
			cin>>l>>r,es.emplace_back(l,r),
			son[l].emplace_back(r),
			son[r].emplace_back(l);
		for(const auto&e:es){
			cl=e.first; cr=e.second;
			cur[cl]=cur[cr]=1;
			cv[0].clear(); cv[1].clear();
			// cerr<<cl<<" "<<cr<<":\n";
			coll(cl,cr); dfs(cl,cr);
			dfc(cl,cr,0); swap(cv[0],cv[1]);
			coll(cr,cl); dfs(cr,cl);
			dfc(cr,cl,0);
			sort(cv[0].begin(),cv[0].end(),greater<int>());
			sort(cv[1].begin(),cv[1].end(),greater<int>());
			// for(int v:cv[0]) cerr<<v<<" "; cerr<<endl;
			// for(int v:cv[1]) cerr<<v<<" "; cerr<<endl;
			for(int i=0;i<=n;++i){
				if(max((int)cv[0].size(),1)+max((int)cv[1].size(),1)<=m){
					ans=min(ans,i); break;
				}
				while(cv[0].size()&&cv[0].back()<=i) cv[0].pop_back();
				while(cv[1].size()&&cv[1].back()<=i) cv[1].pop_back();
			}
			memset(lf,0,sizeof lf);
			cur[cl]=cur[cr]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//1709 passed 40pts samples.
//no time to check, preserved for T3