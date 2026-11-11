#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10;
int t[N];
void add(int x,int d){
	for(int i=x;i<=n;i+=i&(-i)){
		t[i]+=d;
	}
}
int query(int x){
	int ret=0;
	for(int i=x;i;i-=i&(-i)){
		ret+=t[i];
	}
	return ret;
}
int lst[N];
int a[N];
int ans[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(lst[a[i]]!=0){
			add(lst[a[i]],-lst[a[i]]);
			add(i,lst[a[i]]);
		}
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int ad=i+query(i);
		ans[a[i]]+=ad;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
//SN-J01046 Íõè÷·² card
