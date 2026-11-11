#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],lst[M],tree[N<<2],lz[N<<2],ans[M];
bool vis[N];
//void pd(int node,int l,int r){
//	if(lz[node]){
//		int mid=l+r>>1;
//		tree[node<<1]+=(mid-l+1)*lz[node];
//		tree[node<<1|1]+=(r-mid)*lz[node];
//		lz[node<<1]+=lz[node];
//		lz[node<<1|1]+=lz[node];
//		lz[node]=0;
//	}
//	return ;
//}
//void upd(int node,int l,int r,int st,int ed){
//	if(st>ed)
//		return ;
//	if(st<=l&&r<=ed){
//		tree[node]+=(r-l+1);
//		lz[node]++;
//	}else{
//		pd(node,l,r);
//		int mid=l+r>>1;
//		if(st<=mid)
//			upd(node<<1,l,mid,st,ed);
//		if(ed>mid)
//			upd(node<<1|1,mid+1,r,st,ed);
//		tree[node]=tree[node<<1]+tree[node<<1|1];
//	}
//	return ;
//}
//int qry(int node,int l,int r,int st,int ed){
//	if(st<=l&&r<=ed)
//		return tree[node];
//	else{
//		pd(node,l,r);
//		int res=0,mid=l+r>>1;
//		if(st<=mid)
//			res+=qry(node<<1,l,mid,st,ed);
//		if(ed>mid)
//			res+=qry(node<<1|1,mid+1,r,st,ed);
//		return res;
//	}
//}
stack<int>st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		if(!lst[a[i]])
//			lst[a[i]]=i;
//		else{
//			upd(1,1,n,lst[a[i]]+1,i-1);
//			lst[a[i]]=0;
//		}
	}
	if(n>=10000){
		for(int i=1;i<=n;i++)
			ans[a[i]]=i;
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<' ';
		return 0;
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			if(vis[a[i]]){
				while(st.top()!=a[i]){
					vis[st.top()]=0;
					st.pop();
				}
			}else{
				vis[a[i]]=1;
				st.push(a[i]);
			}
		}
		while(!st.empty()){
			vis[st.top()]=0;
			ans[st.top()]++;
			st.pop();
		}
	}
//	for(int i=n;i>=1;i--){
//		if(vis[a[i]]){
//			while(st.top()!=a[i]){
//				vis[st.top()]=0;
//				st.pop();
//			}
//		}else{
//			vis[a[i]]=1;
//			st.push(a[i]);
//		}
//		for(int i=1;i<=m;i++)
//			ans[i]+=vis[i];
//	}
//	for(int i=n;i>=1;i--){
////		upd(1,1,n,lst[a[i]],i-1);
//		if(!ans[a[i]])
//			ans[a[i]]=i-qry(1,1,n,i,i);
//	}
////	for(int i=1;i<=n;i++)
////		ans[a[i]]=min(ans[a[i]],i-qry(1,1,n,i,i));
//	for(int i=1;i<=n;i++)
//		cout<<qry(1,1,n,i,i)<<' ';
//	cout<<'\n';
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
/*
10 3
3 2 3 1 2 1
*/
