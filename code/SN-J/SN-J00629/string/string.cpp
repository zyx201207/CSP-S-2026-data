//王彦龙 庆安初级中学 SN-J00629 
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+10;

int n;
int a[N];
char c[N];

struct node{
	int id,val; 
};

deque<node> q;

signed main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	
	int ans=0;
	for(int i=1;i<=n;i++) q.push_back({i,a[i]});
		
	node tmp1,tmp2;
	int u=0,v=0,val1=0,val2=0;
		
	while(!q.empty()){
		if(q.size()<=1){
			break; //剩下一个元素不用改 
		}
		node tmp1=q.front(),tmp2=q.back();
		q.pop_front(); q.pop_back();
		
		int u=tmp1.id,v=tmp2.id;
		int v1=tmp1.val,v2=tmp2.val;
		
		if(c[u]!=c[v]) ans+=min(v1,v2);
		if(v1>v2) q.push_front({u,v1-v2});
		else if(v1<v2) q.push_back({v,v2-v1});
	}
	
	cout<<ans;
	
	return 0;
	
}
