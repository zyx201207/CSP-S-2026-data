#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
map<int,int>q;
bool vis[300050];
int cnt[300050];
int len=0;
int ans[300050];
int endd[300050];
bool count1(){
	for(int i=1;i<n;++i){
		if(a[i]>a[i+1]){
			return 0;
		}
	}
	return 1;
}
void moni(int x){
	q.clear();
	for(int i=x;i<=n;++i){
		if(q[a[i]]!=0){
			for(int j=q[a[i]];j<i;++j){
				q[a[j]]=0;
			}
		}
		q[a[i]]=i;
	}
	for(int i=1;i<=len;++i){
		if(q[cnt[i]]!=0){
			++ans[cnt[i]];
		}
	}
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		if(vis[a[i]]==0){
			++len;
			cnt[len]=a[i];
			vis[a[i]]=1;
		}
	}
	bool xingzhiA=1;
	if(!count1()){
		xingzhiA=0;
	}
	if(xingzhiA){
		for(int i=1;i<=n;++i){
			endd[a[i]]=i;
		}
		for(int i=1;i<=m;++i){
			cout<<endd[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		moni(i);
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
