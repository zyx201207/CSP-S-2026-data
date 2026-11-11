#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N],top[N];
/*
4 3
1 2 1 3
*/
/*
10 3 
3 1 2 1 3 2 3 1 2 1
*/
struct node{
	int l;
	int r;
};
vector<node> seg;
bool cmp(node p,node q){
	if(p.l==q.l) return p.r>q.r;
	return p.l<q.l;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(top[a[i]]) seg.push_back({top[a[i]],i-1});
		top[a[i]]=i;
	}
	sort(seg.begin(),seg.end(),cmp);
	//for(int x=0;x<seg.size();x++) cout<<seg[x].l<<" "<<seg[x].r<<endl;
	int lst=1;
	for(int i=1;i<n;i++){
		int x=0;
		for(x;x<seg.size();x++) if(seg[x].l==a[i]) break;
		while(seg[x].r<n-1){
			while(seg[x+1].l<seg[x].r+1){
				ans[a[seg[x].r]]++;
				x++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(a[n]!=i) cout<<ans[i]<<" ";
		else cout<<n<<" ";
	}
	return 0;
}
