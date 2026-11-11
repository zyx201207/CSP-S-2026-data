#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=2e5+10;
struct node{
	int num;
	char ch;
}a[N];
int n,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;
	}
	int l=1,lid=1,r=1,rid=n;
	while(lid<=rid){
		int t=min(a[lid].num-l+1,a[rid].num-r+1);
		if(a[lid].ch!=a[rid].ch) ans+=t;
		if(a[lid].num-l+1==t){
			lid++;
			l=1;
		}else{
			l+=t;
		} 
		if(a[rid].num-r+1==t){
			rid--;
			r=1;
		}else{
			r+=t;
		} 
		if(l>a[lid].num){
			lid++;
			l=1;
		}
		if(r>a[rid].num){
			rid--;
			r=1;
		}
	}
	cout<<ans;
	return 0;
}

