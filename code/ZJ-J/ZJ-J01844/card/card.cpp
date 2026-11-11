#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500001],lstj[200001],cnt,w=2,ans[200001];
struct node{
	int l,r;
	bool operator<(const node&s)const{
		return l<s.l;
	}
}k[500002];
vector<int> lst[200001];
deque<int> dq;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(lstj[a[i]]) k[++cnt]={lstj[a[i]],i};
		lstj[a[i]]=i;
	}
	k[++cnt]={0,n+1};
	sort(k+1,k+cnt+1);
	memset(lstj,0,sizeof(lstj));
	dq.push_front(1);
	for(int i=1;i<=n;i++){   
		while(k[dq.back()].r<=i) dq.pop_back();            
		int l=k[dq.back()].l;
		while(!lst[a[i]].empty()&&k[lst[a[i]].back()].r<=i) lst[a[i]].pop_back();
		if(lst[a[i]].empty()||dq.back()!=lst[a[i]].back()){
			ans[a[i]]+=i-l;
			lst[a[i]].push_back(dq.back());
			lstj[a[i]]=i-l;
		}
		else{
			ans[a[i]]=ans[a[i]]-lstj[a[i]]+i-l;
			lstj[a[i]]=i-l;
		}
		if(w!=cnt+1&&k[w].l==i) dq.push_back(w++);
	}
	for(int i=1;i<=m;i++){
		cout<<min(ans[i],n)<<' ';
	}
}