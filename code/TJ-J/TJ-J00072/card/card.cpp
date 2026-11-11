#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[300005],t[300005];
int find(int x){
	for(int i=1;i<=n;i++){
		if(a[i]==x)return i;
	}return -1;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}for(int i=1;i<=m;i++){
		cout<<find(i)+t[i]-1<<" ";
	}
	
	
	return 0;
}
